package com.example.recycleviewexample;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Path;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.bumptech.glide.Glide;

import java.io.File;

import de.hdodenhof.circleimageview.CircleImageView;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;

public class Applyactivity extends AppCompatActivity {
    private CircleImageView profileImage;
    private EditText editid;
    private EditText editpassword;
    private EditText editpassword2;
    private Button editbutton;
    private Uri uri;
    private File file;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_applyactivity);

        init();
        setListerer();
    }
    private void init(){
        profileImage=findViewById(R.id.profileImage);
        editid = findViewById(R.id.editid);
        editpassword = findViewById(R.id.editpassword);
        editpassword2 = findViewById(R.id.editpassword2);
        editbutton = findViewById(R.id.editbutton);
    }

    private void setListerer(){
        profileImage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(ContextCompat.checkSelfPermission(Applyactivity.this,
                        Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED){
                    ActivityCompat.requestPermissions(Applyactivity.this,
                            new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, 3000);
                }
                else{
                    requestImage();
                }
            }
        });

        editbutton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(editpassword.getText().toString().equals(editpassword2.getText().toString())){
                    Userservice userservice = RetrofitUtil.retrofit.create(Userservice.class);
                    Call<DefaultResponse> call = userservice.apply(
                            new User(editid.getText().toString(), editpassword.getText().toString()),
                            RetrofitUtil.createMultipartBody(file,"profile"));
                    call.enqueue(new Callback<DefaultResponse>() {
                        @Override
                        public void onResponse(Call<DefaultResponse> call, Response<DefaultResponse> response) {
                            if(response.body().getResult().isSuccess()){
                                Toast.makeText(getApplicationContext(), response.body().getResult().getMessage(),
                                        Toast.LENGTH_SHORT).show();
                            }
                            else
                            {
                                Log.e("error",response.message());
                            }
                        }

                        @Override
                        public void onFailure(Call<DefaultResponse> call, Throwable t) {

                        }
                    });
                }
            }
        });
    }



    private void requestImage(){
        Intent OpenGalleryIntent = new Intent(Intent.ACTION_PICK);
        OpenGalleryIntent.setType("image/*");
        startActivityForResult(OpenGalleryIntent,5000);
    }

    @Override
    public void onRequestPermissionsResult (int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode == 3000 && grantResults[0] == PackageManager.PERMISSION_DENIED) {
            requestImage();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 5000 && resultCode == RESULT_OK) {
            uri = data.getData();
            ImageView profileImage = null;
            Glide.with(this).load(uri).into(profileImage);
            file = new File(getRealPathFromUri(uri));
        }
    }

    private String getRealPathFromUri(Uri contentUri){
        Cursor cursor = getContentResolver().query(contentUri, null,null,null,null);
        if(cursor==null)
            return contentUri.getPath();
        else{
            cursor.moveToFirst();
            int idx = cursor.getColumnIndex(MediaStore.Images.ImageColumns.DATA);
            return cursor.getString(idx);
        }
    }
}

package com.example.recycleviewexample;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.recycleviewexample.model.AuthRequest;
import com.example.recycleviewexample.model.AuthResponse;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class LoginActivity extends AppCompatActivity {

    public TextView gotoapply;
    private Button button;
    private EditText editid;
    private EditText editpassword;

    private static final String TAG = LoginActivity.class.getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        init();
        setListener();
    }

    private void init(){
        gotoapply = findViewById(R.id.gotoapply);
        button = findViewById(R.id.editbutton);
        editid = findViewById(R.id.editid);
        editpassword = findViewById(R.id.editpassword);
    }
    private void setListener() {
        gotoapply.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(LoginActivity.this, Applyactivity.class);
                startActivity(intent);
            }
        });

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                login();
            }
        });
    }
    private void login(){
        String email = editid.getText().toString();
        String password = editpassword.getText().toString();

        Userservice userservice = RetrofitUtil.retrofit.create(Userservice.class);
        Call<AuthResponse> call = userservice.sign(
                new AuthRequest(email,password));
        call.enqueue(new Callback<AuthResponse>() {
            @Override
            public void onResponse(Call<AuthResponse> call, Response<AuthResponse> response) {
                if(response.body().getResult().isSuccess()) {
                    com.example.recyclerviewexample.SharedPreferenceUtil.putSharedPreference(getApplicationContext(),"token",response.body().getAuth().getToken());

                    startActivity(new Intent(LoginActivity.this, Applyactivity.class));
                    Toast.makeText(getApplicationContext(),"로그인 성공",Toast.LENGTH_SHORT).show();
                } else {
                    Log.e(TAG,response.body().getResult().getMessage());
                }
            }

            @Override
            public void onFailure(Call<AuthResponse> call, Throwable t) {
                Log.e(TAG, t.getLocalizedMessage());
            }
        });
    }
}

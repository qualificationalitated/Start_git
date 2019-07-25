package com.example.study_2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private EditText num1;
    private EditText num2;
    private EditText num3;
    private EditText num4;
    private EditText num5;
    private EditText num6;
    private EditText num7;
    private EditText num8;

    private Button plusButton;
    private Button minusButton;
    private Button gopButton;
    private Button divButton;

    private TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        num1=findViewById(R.id.num1);
        num2=findViewById(R.id.num2);
        num3=findViewById(R.id.num3);
        num4=findViewById(R.id.num4);
        num5=findViewById(R.id.num5);
        num6=findViewById(R.id.num6);
        num7=findViewById(R.id.num7);
        num8=findViewById(R.id.num8);

        plusButton = findViewById(R.id.plusButton);
        minusButton = findViewById(R.id.minusButton);
        gopButton = findViewById(R.id.gopButton);
        divButton = findViewById(R.id.divButton);

        textView = findViewById(R.id.textView);
        plusButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int result = Integer.parseInt(num1.getText().toString())+Integer.parseInt(num2.getText().toString());
                textView.setText("결과는 : " + result);
            }
        });
        minusButton.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        int result = Integer.parseInt(num3.getText().toString())-Integer.parseInt(num4.getText().toString());
                        textView.setText("결과는 : " + result);
                    }
                });
        gopButton.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                int result = Integer.parseInt(num5.getText().toString())*Integer.parseInt(num6.getText().toString());
                                textView.setText("결과는 : " + result);
                            }
                        });
        divButton.setOnClickListener(new View.OnClickListener() {
                                    @Override
                                    public void onClick(View view) {
                                        int result = Integer.parseInt(num7.getText().toString())/Integer.parseInt(num8.getText().toString());
                                        textView.setText("결과는 : " + result);
                                    }
                                });

    }

    @Override
    public void finish() { // 맨 마지막 실행되는 메소드 finish
        Toast.makeText(getApplicationContext(),"하하 난 죽었다",Toast.LENGTH_SHORT).show();
    }
}

package com.example.pragmentexample;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MenuItem;
import android.widget.Switch;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class MainActivity extends AppCompatActivity {
    private BottomNavigationView bottomNavigationView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bottomNavigationView = findViewById(R.id.bottom_view);
        bottomNavigationView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                switch(item.getItemId()){
                    case R.id.menu1:{
                        getSupportFragmentManager().beginTransaction()
                                .replace(R.id.content_main, first_pragnent.newInstance())
                                .commit();
                        return true;
                    }
                    case R.id.menu2:{
                        getSupportFragmentManager().beginTransaction()
                                .replace(R.id.content_main, Second_Pragment.newInstance())
                                .commit();
                        return true;
                    }
                    case R.id.menu3:{
                        getSupportFragmentManager().beginTransaction()
                                .replace(R.id.content_main, Thrid_Pragment.newInstance())
                                .commit();
                        return true;
                    }
                }
                return false;
            }
        });
    }
}

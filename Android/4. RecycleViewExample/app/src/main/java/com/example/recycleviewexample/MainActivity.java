package com.example.recycleviewexample;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import com.example.recycleviewexample.model.Item;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private ArrayList<Item> itemlist = new ArrayList();
    private RecyclerView recyclerView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    private void init()
    {
        recyclerView=findViewById(R.id.recyclerView);
    }
    private void addDummy(){
        itemlist.add(new Item("test1","test1"));
        itemlist.add(new Item("test2","test2"));
        itemlist.add(new Item("test3","test3"));
        itemlist.add(new Item("test4","test4"));
        itemlist.add(new Item("test5","test5"));
        itemlist.add(new Item("test6","test6"));
        itemlist.add(new Item("test7","test7"));
        itemlist.add(new Item("test8","test8"));
        itemlist.add(new Item("test9","test9"));
    }
    private void setRecyclerView(){
        recyclerView.setAdapter(new ItemRecyclerAdapter(itemlist));
        RecyclerView.LayoutManager layoutManager=new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setHasFixedSize(true);
    }
}

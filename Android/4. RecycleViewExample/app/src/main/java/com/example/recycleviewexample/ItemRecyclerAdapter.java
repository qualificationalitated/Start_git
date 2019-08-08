package com.example.recycleviewexample;

import android.content.ClipData;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextClock;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

// 퍼블릭클래스는 이름이 같아야한다.

public class ItemRecyclerAdapter extends RecyclerView.Adapter<ViewHolder> {
    private ArrayList<Item> itemList;
    public ItemRecyclerAdapter(ArrayList<Item> itemList) {
        this.itemList = itemList;
    }
    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater=(LayoutInflater) parent.getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View itemView = inflater.inflate(R.layout.item_dafault, parent, false);
        return  new ViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        Item item = itemList.get(position);
        holder.title.setText(item.getTitle());
        holder.content.setText(item.getContent());

    }

    @Override
    public int getItemCount() {
        return itemList.size();
    }
}

class ViewHolder extends RecyclerView.ViewHolder {

    TextView title;
    TextView content;
    public ViewHolder(@NonNull View itemView) {
        super(itemView);
        title=itemView.findViewById(R.id.title);
        content=itemView.findViewById(R.id.content);
    }
}
inherit NPC;
inherit SELLMAN;
void create()
{
       set_name("酒店老闆",({"owner"}));
       set("long",@LONG
    這個中年男子是「獨角鯨的低喃」的老闆，他本來是一名水手，隨船
來到薩爾薩斯港的時候，發現這裡竟然沒有酒店！他一氣之下就在這裡開
了第一家酒店。他本來水手的個性仍然沒改，豪爽的作風也吸引了很多冒
險者，這也使得他的店總是充滿了人以及笑聲。
LONG
);
       set("gender","男性");
       set("age", 45);
       set("level", 20);
       set("attitude", "peaceful");
       
       set("sell_list",([       
           __DIR__"obj/beer"  : 25, 
           __DIR__"obj/fish"  : 25
       ]) );                                 
        set("talk_reply","我是沒什麼事啦！但是港務公所的露西似乎在煩惱著什麼。\n");   
        setup();
        
}
void init()
{       
        add_action("do_list","list");
        add_action("do_buy","buy");
}


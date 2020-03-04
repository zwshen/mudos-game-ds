#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name(YEL"西西莉"NOR,({"cecily"}));
       set("long",@LONG
    一個十分美麗的女子正站在這裡，深邃的眼眸中含著聰慧的光芒，緊
閉的雙唇訴說著她的堅強。頂著一頭俐落的金黃短髮，纖細的身軀毫不猶
豫地指揮著商會中大大小小的事務，她是商人普爾的妹妹，也是薩爾薩斯
著名的美人。不過雖然她各方面都十分的好，但是對男人而言她卻有一個
十分重大的缺點─她只喜歡女人。
LONG);
       set("gender","女性");
       set("age", 23);
       set("level", 15);
       set("chat_chance", 3);
       set("chat_msg", ({
            "西西莉俐落的指揮著夥計們搬運商品。\n",
            "西西莉在她手上的本子上記下一些東西。\n",
            "西西莉擦了擦頭上的汗，吁了一大口氣，又繼續忙碌了。\n"
           }));
       set("talk_reply",".....(西西莉指著一個夥計，看來是叫你有事就去找夥計談吧！)\n");
       set("storeroom",__DIR__"obj/shop");
       set("no_fight",1);
       setup();
       carry_object( __DIR__"eq/dress")->wear();         

}
void init()
{         
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
          add_action("do_buy","buy");
          add_action("do_sell","sell");
          add_action("do_list","list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( ob->query("gender") ) {
           case "男性":
               say("西西莉懶懶看了"+ob->query("name")+"一眼，嘆了口氣，又回過頭做自己的事了。\n");
               break;
           case "女性":
               if(ob->query("age")>30)
               {
                 say("西西莉懶懶看了"+ob->query("name")+"一眼，嘆了口氣，又回過頭做自己的事了。\n");
                }
                else{
                 say("西西莉眼睛一亮！盯著"+ob->query("name")+"看了好一會兒。\n");
                 command("blush");
                }
               break;
           default:    
                say("西西莉轉過頭，好奇的盯著" + ob->query("name") +"左看右看。\n");
                break;
        }
}



inherit ITEM;
inherit F_UNIQUE;
void create()
{
set_name("三君子柳",({"three-gentlemen tree","tree"}));
set_weight(9999);
set("unit","株");
set("long",
      "     這三棵柳樹以前一後二的形式排列，由於它們的\n"
      " 枝葉並非像普通柳樹般垂向水濱，而是垂向山徑。看\n"
      " 起來就像三個人在對經過的路人行禮一般，所以附近\n"         
      " 的居民稱之為三君子，也有人叫它迎賓樹。\n"
);   
		set("no_get",1);
		set("no_sac",1);

setup();
}

void init()
{
       add_action("do_search","search");   
}
int do_search(string arg)
{
  object me=this_player();
                    if (arg != "三君子柳" && arg !="tree"&&arg !="three-gentlemen tree" )
                return 0;
                   else
                   {
                              tell_object(me,"仔細一看，這三株柳樹似乎是有人刻意種植成這樣的！！！\n");
                              tell_object(me,"看這個形式，似乎像個指向東邊的箭頭......\n");
                              tell_object(me,"可是東邊只有一片高至人肩的雜草和遠處的山壁，難道......\n");
                         }
               return 1;
}

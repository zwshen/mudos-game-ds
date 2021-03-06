#include <ansi.h>
inherit NPC;
void gotoinn();

void create()
{
 set_name("陳崎",({"chen chi","chen","chi"}));
 set("long",@LONG
據說他早年曾經雲遊四海，直到老年才回到苗家村逍遙度日
閒時吟吟詩，作作對，不失為一代儒生之表！
LONG
    );
 set("attitude", "peaceful");
 set("age",64);
 set("nickname",CYN"山野村夫"NOR);
 set("evil",-10);
 set("gender","男性");
 set("level",30);
set("str",100);
set("con",100);
 set_skill("sword", 100);
 set("chat_chance",10);
 set("no_kill",1);
 set("chat_msg", ({"陳崎嘆了一口長氣：難道當真對不出來.....？\n", 
        }) );
set("schedule",
([
    "00" : (: gotoinn :),
    "05" : (: gotoinn :),
    "10" : (: gotoinn :),
    "15" : (: gotoinn :),
    "20" : (: gotoinn :),
]));

 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

void gotoinn()
{
 int a=random(7);
        if(!find_object("/open/world1/tmr/area/hotel")) return;
        if(!find_object("/open/world1/cominging/area/hotel")) return;
        if(!find_object("/open/world1/acme/area/hotel")) return;
        if(!find_object("/open/world1/moonhide/area/hotel")) return;
        if(!find_object("/open/world1/wilfred/sand/room12")) return;
        if(!find_object("/open/world1/whoami/birdarea/village8")) return;
        if(!find_object("/open/world1/faceoff/sky/ten16")) return;

 message_vision("$N伸伸懶腰，緩緩的走了出去•\n", this_object());
 if( a == 0 ) {
   if( file_name(environment(this_object())) == "/open/world1/moonhide/area/hotel" ) a++;
   else this_object()->move("/open/world1/moonhide/area/hotel"); 
 }
 if( a == 1 ) {
   if( file_name(environment(this_object())) == "/open/world1/cominging/area/hotel" ) a++;
   else this_object()->move("/open/world1/cominging/area/hotel");
 } 
 if( a == 2 ) {
   if( file_name(environment(this_object())) == "/open/world1/acme/area/hotel" ) a++;
   else this_object()->move("/open/world1/acme/area/hotel");
 }
 if( a == 3 ) {
   if( file_name(environment(this_object())) == "/open/world1/tmr/area/hotel" ) a++;
   else this_object()->move("/open/world1/tmr/area/hotel");
 }
 if( a == 4 ) {
   if( file_name(environment(this_object())) == "/open/world1/wilfred/sand/room12" ) a++;
   else this_object()->move("/open/world1/wilfred/sand/room12");
 }
 if( a == 5 ) {
   if( file_name(environment(this_object())) == "/open/world1/whoami/birdarea/village8" ) a++;
   else this_object()->move("/open/world1/whoami/birdarea/village8");
 }
 if( a == 6 ) {
   if( file_name(environment(this_object())) == "/open/world1/faceoff/sky/ten16" ) a=0;
   else this_object()->move("/open/world1/faceoff/sky/ten16");
 }
 message_vision("$N伸伸懶腰，緩緩的走了進來•\n", this_object());
}


int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 if(random(2))
 {
   if (me->query("int") > 30)
    {
        command("say 看來小老弟應該可以幫忙一下。");
        command("say 是這樣的：前幾天出遠門時在一個餐\館看到了一個對聯...");
      command("say 上聯是：「凍雨洒窗，東二點，西三點」，任憑老夫怎麼想也想不出下聯 ");
      command("say 小老弟如果對的齊, 是否可以指教(answer)一下？");
    }
    else
    {
        command("say 老夫一點小事不敢麻煩老弟....^^");
    }
 }
 return 1;
}

void init()
{
        add_action("do_answer","answer");
}

void clear() {
        if(!this_object()) return ;
        delete("quest");
}

int do_answer(string arg)
{
        object me,where1,p;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten42");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式: answer <下聯>\n");
        if ( query("quest") ) {
            message_vision("陳崎微笑道: 多謝老弟，剛才已經有人指教過老夫了！ \n",me);
                return 1;
        }
        
        if( a == "切糕分客，上七刀，下八刀" || a =="切瓜分客，上七刀，下八刀" || a =="切瓜分片，上七刀，下八刀" )
   {
      message_vision("$N緩緩吟道："+a+"\n",me);
        message_vision("陳崎愣了一愣， 隨即高興的握住$N的手！ \n",me);
        message_vision("陳崎說道: 小老弟真智者也！ \n",me);
        message_vision("陳崎說道: 早些年因緣際會得到了幾個小東西，在我身上也沒什麼用，小老弟拿去吧！ \n",me);
       message_vision(HIC"陳崎給了$N一些金色的丹藥！ \n"NOR,me);
        new(__DIR__"obj/gold_pill.c")->move(this_player());
        set("quest", 1) ;
        call_out("clear", 1800 + random(1800));
        gotoinn();
        return 1;
    }

    message_vision("陳崎搖了搖頭，說道:不夠工整啊....\n",me);
    return 1;
}


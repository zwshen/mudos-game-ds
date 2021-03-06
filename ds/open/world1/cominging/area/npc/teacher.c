#include <ansi.h>
#include <net/dns.h>
inherit NPC;

int COUNT = 0;

void do_teach();

void create()
{
        set_name("宋文公",({"song wen gon", "gon","song" }) );
        set("long",
                "傳聞在幾年前曾經當過丞相助手的一個老師，所以各\n"
                "地都有人前來招募他，他現在在步靈城一家小私塾教書，\n"
                "有機緣的人，說不定還可以跟他學到不一樣的知識喔！\n");
        set("title","老師");
        set("age", 40+random(10));
        set("level",25);
        set("gender","男性");
        set("race","人類");

        set("chat_chance", 10);
        set("chat_msg",({ 
  (: do_teach :),
  (: do_teach :),
  (: command,"yawn" :),
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
}));
        set("str",30);
        set("no_fight",1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("fogseven",60);
        map_skill("dodge","fogseven");

        set("flurrydodge",1);
        setup();
        carry_object(__DIR__"wp/book.c")->wield();
        carry_object(__DIR__"eq/whiterobe.c")->wear();
}

void do_teach()
{
        object ob,*s;
        string *a,arg;
        int j;

        ob=this_object();

        if( ob->is_fighting() ) return;
        
        //      為避免文章檔案意外被砍
        //      請把以下程式保留, 當找無此檔時, 可以有取代文字.
        if( file_size(__DIR__"teacher_read.txt") > 0 ) //luky
        {
                a = explode(read_file(__DIR__"teacher_read.txt"),"\n");
        }
        else a = ({
                "熬夜對身體不好。",
                "春游浩蕩，是年年寒食，梨花時節。白錦無紋香爛漫，玉樹瓊苞堆雪。",
                "我十八歲，我不抽煙。",
                "靜夜沉沉，浮光靄靄，冷浸溶溶月。人間天上，瀾銀霞照通徹。",
                "夢幻七域真好玩，大家一起打廣告。",
                "渾似姑射真人，天姿靈秀，意氣殊高潔。萬蕊參差誰信道，不與群芳同列。",
                "浩氣清英，仙才卓犖，下土難分別。瑤台歸去，洞天方看清絕。",
                "作這一首《無俗念》詞的，乃南宋末年一位武學名家，有道之士。",
                "哇哈哈!! 哇哈哈!! 夢幻七域真有趣，哥哥姊姊都來玩。",
        "這麼晚了還不睡覺嗎？",
        "秋風清，秋月明；落葉聚還散，寒鴉栖復驚。",
        "相思相見知何日，此時此夜難為情。",
        "明天不用上課嗎？",
        "兵火有餘燼，貧村纔數家。無人爭曉渡，殘月下寒沙。",
        "小桃無主自開花，煙草茫茫帶晚鴉。幾處敗垣圍故井，向來一一是人家。",
        "這首七言詩，說的是兵火過後，原來的家家戶戶都成了敗垣殘瓦之地。",
        "別去光顧鎮上的長慶樓，那兒的江瑤柱是陳年宿貨，會吃出人命來的。",
        "治小感冒可用血竭、田七、熊膽、沒藥四味煎服，立見奇效。",
                });

        if( COUNT >= sizeof(a) )
        {
                COUNT = 0;
                arg = "今天先念到這, 下回待續";
        }
        else arg = a[COUNT];

        COUNT++;
        message_vision(HIG"$N唸道："+arg+"\n"NOR,this_object());

        s = all_inventory(environment(this_object() ));

        for(j=0;j<sizeof(s);j++)
        {
                if(s[j]->query_temp("Confucius") )
                {
                        if( s[j]->query_temp("netdead") == 1 ) continue;
                        // 斷線的人不能跟著讀書...add by -Acme-
//                      if( arg!="none" ) message_vision(NOR""+YEL"$N跟著念道："+arg+"\n"NOR,s[j] );
//                      if( arg!="none" ) tell_object(s[j],"你聽了聽"+this_object()->name()+"所說的這一段話，頗有了解。\n");
                        if( s[j]->query_skill("literate", 1) < 70 )
                         s[j]->improve_skill("literate", random( s[j]->query_int()/9+5 ));
                }
        }
        return;
}

void init()
{
        if( this_player()->query_temp("Confucius") )
                this_player()->delete_temp("Confucius");
        if( this_player()->query("id") == "phoenix" && !userp(this_player()) )
        {
            command("kick "+this_player()->query("id"));
            this_player()->move("/open/world1/cominging/area/sidestreet3.c");
        } 
        add_action("do_sit","sit");
}

int do_sit()
{
        object me;
        me=this_player();

        if( me->query_temp("Confucius"))
          return notify_fail("你已坐下來專心聽講了。\n");
        if( me->is_fighting() )
                return notify_fail("你正忙著打架，沒空聽課！\n");
        if( me->is_ghost() )
                return notify_fail("都死了，還讀什麼書..:P！\n");
        if( me->is_busy() )
                return notify_fail("你正忙著，沒有空聽課。\n");
        if( me->query_skill("literate",1) > 70 )
                return notify_fail("這裡已經沒辦法再教你什麼了，去更好的老師的地方吧。\n");
//      if( me->query_skill("literate",1) < 30 )
//              return notify_fail("你因為讀書識字還不怎麼熟練，所以還聽不怎麼懂。\n");

        message_vision("$N在旁找了個位子坐了下來，專心讀書。\n",me);
        me->set_temp("Confucius",1);
        return 1;
}


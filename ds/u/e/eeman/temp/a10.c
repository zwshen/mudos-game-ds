#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIC"斯蘭街"NOR);
        set("long", "古老的街景，碩大的石磚，這條類似中古世紀歐洲的街道充滿著
古意盎然的模樣。兩排的櫻木開滿了茂盛的枝葉，地下舖著用櫻花做
的地毯，在樹底下有著幾對情侶在談情，也有家人一起來賞櫻的，一
幅美麗的圖案顯現在你的眼前。北面有著世界著名的武匠達加開的武
器屋。
");
        set("exits",([
        "east":__DIR__"a06",
//      "north":__DIR__"a11",
        ]));
        set("outdoor",1);
        set("objects",([
        __DIR__"npc/thief1":1,
        ]));
        set("light",1);
        setup();
}

void init()
{
        call_out("war_check",30);
}

void war_check()
{
        object ob;
        ob=this_object();
        remove_call_out("war_check"); //luky
        if(ob->query("war"))
        {
        ob->set("war",0);
        shout("\n\n\n"
        +HIW"               躲在城外的盜賊看到緊急的信號\n\n"NOR
        +HIR"               發現前去把風的探子被人陳屍在街上\n\n"NOR
        +HIW"               盜賊首領忿怒的下令血洗村莊\n\n"NOR);
        new(__DIR__"npc/thief.c")->move(__DIR__"a06");
        new(__DIR__"npc/thief.c")->move(__DIR__"a06");
        ob->set("WarStart",1);
        call_out("war_report",30);
	}
	else call_out("war_check",30);
}

void war_report()
{
        object obj,ob,where;
        remove_call_out("war_report"); //luky
        if( this_object()->query("time") > 1 )	// >1 為30秒的樣子.....
	{					//如果要更久就弄大的數字
		this_object()->set("time",0);
                this_object()->set("WarStart",0);

		for(int i=0;i<5;i++)	//這裡依照此war會招出多少mob而定
		{			//有幾隻mob出現,i就小於多少隻mob
		        ob=find_living("lanka thief");
			if(ob)
				destruct(ob);
		}

                shout("\n\n"
                +HIM"               蘭卡城的盜賊跑掉了\n\n"NOR);
		return;
	}

        if(this_object()->query("WarStart"))
        {
        	obj=find_living("lanka thief");
        	where=environment(obj);
        	if(!where)
                {
                	shout("\n\n"
                	+HIM"               蘭卡城的盜賊被大家同心協力抓到了\n\n"NOR);
                	this_object()->set("WarStart",0);
                }
                else
                {
                	this_object()->add("time",1);
                	call_out("war_report",30);
                }
        }
}


inherit NPC;
string do_book();

void create()
{
	set_name("伽勒米", ({ "jialermi"}) );
        set("long", @LONG
他是一位老學究，厚重的眼鏡下藏著充滿智慧的眼眸。他所擁有知識
在這塊日昇大陸上是屬一屬二的。傳說他是精靈語的專家。
LONG
	);
        set("level",25);
        set("age",80);
	set("race","人類");
	set("gender","男性");
        set("combat_exp", 3000);
        
        set("title","大學者");

        set("talk_reply","嗯...讀書是多美好的事情。\n");
        set("inquiry",([
        "妖精國度":"由精靈所建立的國家，就隱藏在迷霧林之後。\n"
        	   "基本上他們並不喜歡與人打交道。\n",
        "精靈語": "是指精靈之間所用的古老語言，我研究很久囉...\n",
        "迷霧森林":this_object()->do_book(),
        ]));
        setup();
}
string do_book()
{
	object book,me;
	me=this_player();
	if(!me) return 0;      
        if(objectp(book=present("adventure notebook",me)))
        {
        	book->add_quests_note("fogforest",
        	"為了通過迷霧森林，看來我得去問問村長通過的方法了。\n");
        	me->set_temp("sdoquest/step1",1);
        	return "迷霧森林是一片神秘的樹林。存在的時間遠比你我所想\n像的都還要久，而且會阻擋外來者。聽說村長有精靈朋友，所以他應該知道通過的方法吧\n";
        }
}	
int accept_object(object me,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="魔法書本")
        	return notify_fail("謝謝你，但是我不需要這個。\n");
        if(obj->is_busy() )
        	return notify_fail("我現在沒空！！\n");
        message_vision("$N給了$n一本"+ob->query("name")+"。\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        this_player()->add("popularity",1);
        tell_object(
        "你得到一點聲望！\n");
        message_vision(
        "$n驚訝的說：這....這不是我託人買的書嗎？怎麼會在\n"
        "你手上？能夠拿到真是太好了！\n",me,obj);
        return 1;
}
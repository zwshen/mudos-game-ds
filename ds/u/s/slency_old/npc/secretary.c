#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"思溪"NOR"小秘書" , ({ "Slency's personal secretary","secretary" }) );
        set("class","fighter"); 
        set("race", "人類");
        set("long","一位口愛又天真的秘書ㄛ...只不過她什麼事都不會做..-_-。\n");
        set("con", 100);
        set("str", 100);
        set("level",20);
        set("age",20);
        set("class1",HIW"『 ILLUSION RISER 』"NOR);
        set("title",HIW"『 ILLUSION RISER 』公關"NOR);
        set_skill("sword", 140);
        set_skill("parry",140); 
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        setup();

}
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "思溪")
        
 {
	message_vision("思溪小秘書對$N說道：" HIW "這位客人你好, 需要什麼我替您服務的嗎 ^_^。\n" NOR,me);
        command("wink" + me->query("id"));
 }
	else 
 { 
 	if(me->query("name") == "臥龍")    
       {
        command("hi dragonku");
       }
	else
 {
	command("say 主人你來啦, 挖來乎你放燒水∼  ^ˍ^\n");
	command("wink slency");
 }
 }
}


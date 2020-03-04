#include <ansi.h>
inherit NPC;

void create()
{
	set_name("林西", ({"lam sze","lam","sze"}) );
	set("long", "一個終日無所事事的人,給人專稱醉漢。\n");
            set("nickname",RED"醉漢"NOR);
	set("race", "人類");
	set("age", 40);
	set("level", 25);
	setup();
        carry_object( __DIR__"wp/moon_clip");
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
  object me,guard1,guard2,guard3,obj;
  obj=this_object();
  me=this_player();
  if(me->query_temp("naboo/hatred")>0)
  {
    if(me->query_temp("naboo/hatred")>5)
    {
       if(obj->query_temp("callguard")==0)
       {
         obj->set_temp("callguard",1);
         command("say 惡賊！納命來！！");
         command("kill "+me->query("id"));
         say(YEL"林西大聲喝道：來人啊！把這刺客拿下了！\n");
           say("\n剎那間！突然出現了三名殺手！！\n\n"NOR);
         guard1=new(__DIR__"npc/killer");
         guard2=new(__DIR__"npc/killer");
         guard3=new(__DIR__"npc/killer");
         guard1->move("/u/a/alickyuen/workroom2");
         guard2->move("/u/a/alickyuen/workroom2");
         guard3->move("/u/a/alickyuen/workroom2");
      me->set_temp("naboo/hatred",1);
       }
    }
    else {
      command("say 惡賊！納命來！！");
      command("kill "+me->query("id"));
  }
}
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob )
        {
                ::die();
                return;
        }
  i=ob->query_temp("naboo/hatred");
  if(ob->query_temp("naboo/hatred")==0)
        ob->set_temp("naboo/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}
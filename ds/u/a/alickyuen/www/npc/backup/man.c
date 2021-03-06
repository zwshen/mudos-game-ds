#include <ansi.h>
inherit NPC;
void create()
{
   set_name("喜憨兒",({"retarded","boy","man"}));
   set("level",40);
   set("age", 20);
   set("race","人類");
   set("gender","男性");
   set("unit","位");
   set("no_fight",1);
   set("inquiry",([
       "ct"     : "執行某些動作。\n",
       "rename" : "改變為某人。\n"]));
   set_skill("bagi_fist",100);
   set_skill("da-fork",100);
   set_spell("summon_ghost",100);
   setup();
   set_living_name("_NPC_MAN_");
//   carry_object(__DIR__"../obj/mary_book");
} 

void init()
{ 
    object ob;
    ::init();
    if( interactive(ob = this_player()) )
    {
       remove_call_out("meeting");
       call_out("meeting",0,ob);
    }
    add_action("do_control","ct");
    add_action("do_rename","rename");
}

void meeting(object ob)
{
    array emotes = EMOTE_D->query_all_emote();
    command(emotes[random(sizeof(emotes))]+" "+ob->query("id"));
}

int do_control(string arg)
{
   object mob,me;
   me = this_player();
   mob = this_object();

   if(!wizardp(me))
      return notify_fail(YEL+mob->name()+"緩緩地搖了搖頭.\n"NOR);
   if(!arg)
      return notify_fail(HIW+BLK"[指令]: "HIR"ct <指令>\n"NOR);
   if(geteuid(me) != "www")
   { 
      mob->set_name(me->query("name")+"的小情婦",({"concubine"}));
      mob->set("title",HIR"溼溼小可愛"NOR);
      mob->set_temp("define_look",NOR" 正站在這裡 "HIM"<發浪中>"NOR);
      mob->delete("nickname");
   }
   command(arg);
   return 1;
}

int do_rename(string arg)
{
   mixed data;
   int i;
   string name,id;
   object mob,who,me,eq;

   mob = this_object();
   me = this_player();
   if(!wizardp(me))
      return notify_fail(YEL+mob->name()+"緩緩地搖了搖頭.\n"NOR);
   if(!arg)
      return notify_fail(HIW+BLK"[指令]: "HIR"rename <某人>\n"NOR);
   if(who = present(arg, environment(me))) "";
      else if(who = find_player(arg)) "";
      else return notify_fail("沒有"+arg+"這個人。\n");
   if(mob->query("long"))
     { mob->delete("long"); }
   message_vision("$N的容貌漸漸變成"+who->name(1)+"("+who->query("id")+")。\n",mob);

   // 複製/data/user/內容   
   if(userp(who))
   {
      restore_object(who->query_save_file());
      set_name(who->name(1),({who->query("id"),"boy","man"}));
      mob->set_temp("define_look",NOR" 正站在這裡 "HIM"<發呆中>"NOR);
   }
   // 複製非玩家屬性
   else if(!living(who))
   {
      mob->set_temp("define_look","");
      set_name(who->name(1),({who->query("id"),"boy","man"}));
      mob->set("unit",who->query("unit"));
      mob->set("long",who->query("long"));
      mob->delete("title");
      mob->delete("nickname");
      return 1;
   }

   // 刪除身上所有的物件
   if(sizeof(all_inventory(mob))>1)
   {
      foreach(object ob in all_inventory(mob))
        { destruct(ob); }
   }

   // 複製指定人物身上所有物件
   if(sizeof(all_inventory(who))>1)
   {
      foreach(object ob in all_inventory(who))
        { new(base_name(ob))->move(mob); }
   }

   // living裝備武器及防具
   if(living(who))
   {
      if(who->query_temp("weapon"))
        { command("wield "+who->query_temp("weapon")->query("id")); }
      if(sizeof(who->query_temp("armor"))<1)
        return 1;
      data = values(who->query_temp("armor"));
      foreach(eq in data)
      {
         if(sizeof(data)<1) return 1;
         command("wear "+eq->query("id"));
      }
   }
   return 1;
}

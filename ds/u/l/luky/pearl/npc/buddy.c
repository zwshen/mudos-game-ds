//oceaner.c
#include <path.h>
#include <ansi.h>
#include <dbase.h>
#define STOREDROOM LUKY+"pearl/temp/auto"
inherit NPC;
void create()
{
set_name("夥計",({"buddy"}));
set("level",38);
set("age",32);
set("long","他是本店的夥計, 專門負責外送和補販賣機(Automat)的貨。\n");
set("gender", "男性");
set_skill("tenken",20);
map_skill("unarmed","tenken");
set("coin",300+random(100));
set("chat_chance",8);
set("chat_msg",({
  (:command,"sing":),
"夥計正在偷偷地看著剛買的漫畫書...\n",
"夥計看到漫畫書上的鹹蛋超人忍不住哈哈哈的大笑.\n",
}) );
set("inquiry/automat", @LONG
  如果販賣機沒貨的話, 你可以叫我(tell)補貨.
LONG );
set_temp("apply/armor",random(380));
set_temp("apply/damage",random(76));
set_temp("apply/dodge",random(76));
setup();
set_skill("unarmed",160);
}

void init()
{
add_action("do_tell","tell");
}

int do_tell(string arg)
{
 if(arg=="buddy 補貨" || arg=="buddy supply")
 {
  command("say 你老師沒教你說話要加個'請'字比較有禮貌嗎?"); 
  return 1;	
 }
 if(arg=="buddy 請補貨" || arg=="buddy please")
 {
  message_vision("\n$N告訴夥計說: 請補貨\n",this_player());
  if(this_object()->query("supply"))
  {
   command("say 請等一下, 我待會兒看完漫畫就去補.."); 
   return 1;
  }
  this_object()->set("supply",1);
  call_out("supply1",140);
  call_out("supply2",200);
  command("say 販賣機沒貨了嗎? 好的, 我等一下就去補貨."); 
  return 1;
 }
return 0;
}

void supply1()
{
 command("go south");
 command("go west");
 command("hmm");
 command("say 請等一下, 我立刻開始補貨.");
 set("long","一個道具店的夥計, 正在努力的補販賣機的貨。\n");
 set("chat_chance",25);
 set("chat_msg",({
"夥計正在慢慢的補充販賣機的物品...\n",
"夥計一個不小心把剛剛補好的東西都弄倒了出來.. 夥計又開始重補了..\n",
}) );
}

void supply2()
{
 object stroom, obj;
 if(!find_object(STOREDROOM)) load_object(STOREDROOM);
 stroom=find_object(STOREDROOM);
 if(obj=present("green tea",stroom))
 {
  if(obj->query("amount")<100) obj->set("amount",100);
  command("say 好了, 都補完了. 掰掰!!");
  command("jump");
 } else
 {
  command("say 嗯.. 販賣機好像故障了...我沒辦法..");
  command("shrug"); 
 }
 command("wave"); 
 command("go east");
 command("go north");
 this_object()->delete("supply");
 set("long","他是店的夥計, 專門負責外送和補販賣機的貨。\n");
 set("chat_chance",8);
 set("chat_msg",({
  (:command,"laugh":),
"夥計正在偷偷地看著剛買的漫畫書...\n",
"夥計看到漫畫書上的鹹蛋超人忍不住哈哈哈的大笑.\n",
}) );

}
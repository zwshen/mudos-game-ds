#include <ansi.h>
inherit NPC;

void create()
{
// 設定NPC名稱及ID
set_name(HIY"海龜爸爸"NOR,({"turtle father","turtle","father"}) );
set("long", "一隻笨重的大海龜，背上還有一些小孔。\n");
set("title","狗兄");
// NPC 屬性
set("gender", "男性");
set("level",40);
set("age",31);
// 攻擊與防禦力
add_temp("apply/armor",340);
add_temp("apply/damage",200);
// NPC受攻部位
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"}));
// NPC攻擊動作種類
set("verbs", ({ "bite"}));
setup();
// NPC攜帶錢數
add_money("coin",1000);
set_heart_beat(1);
}

void heart_beat()
{
object *enemy;
object me;
int damage;
int i;
me=this_player();
enemy = me->query_enemy();
enemy[i]=present(enemy[i],environment(me));

//變身條件
if(me->query("hp")<8000&& me->query_temp("change")<1) 
{
message_vision(HIR"\n\n好傢伙!!! 看來不拿出真本事是不行了..\n\n"
+HIB+" 大 海 龜 的 背 上 突 然 伸 出 許 多 毒 刺 !!! \n "NOR,enemy[i]);
me->set_temp("change",1);

//變身後之名稱及敘述
me->set_name(HIM"刺龜"NOR,({"needle turtle","turtle"}));
me->set("long","一隻背上長滿毒刺的海龜。"HIR"(牠似乎非常生氣)\n"NOR);

//變身後之屬性變化
me->add("str",100);
me->add("dex",100);
me->set("max_hp",8000);
me->set("hp",8000);
me->add("exp",20000);
me->add_temp("apply/damage",300);
me->add_temp("apply/armor",360);
}

//變身後之特攻設定
if(me->query_temp("change")==1)
{
 if( me->is_fighting() )
 if(random(300)>200)
    {
damage=700+random(300)-enemy[i]->query_temp("apply/armor");
if(damage<300)
damage=200+random(100);
if(random(100)>50)
message_vision("$N"HIC"突然往你的方向衝過來,重重的向$n一撞,造成"HIR+damage+HIC"傷害!\n"
NOR,me,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
COMBAT_D->report_status(enemy[i],1);
     }
 }
if(me->query("hp")<0)
command("begin war");
::heart_beat();
if(me->query("hp")<0)
 {
  me->die();
 }
}

//死亡時之哀嚎
void die()
{
object ob;
if( !ob = query_temp("last_damage_from") )
ob = this_player(1);
ob->set_temp("kill_turtle",1);
if( !ob ) return;

shout(HIC"\n\n\n          大海中傳來一陣哀嚎∼∼∼\n\n"
+HIR"              啊∼啊∼∼∼∼\n\n"
HIB"        平靜的海面掀起了陣陣的狂濤巨浪 \n\n"NOR);
shout(HIW"大海龜痛苦的大叫: 你∼∼ 愚蠢的"HIY+ob->query("name")+HIW"啊!! 海神是不會放過你的!!!"+
HIR"\n\n      我神海克力斯啊∼∼請幫我守護這片大海吧!!! \n\n"NOR);
::die();
}

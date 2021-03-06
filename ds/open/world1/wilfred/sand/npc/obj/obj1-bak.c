#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

int hit;
int again, index;

void create()
{
  set_name(HIC"究極奧義"NOR,({"final book","book"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",NOR""
WHT"『八極大架-最終式　崩擊雲身雙掌打"HIW"(triple)"NOR""
WHT"』，書僅數頁，裡頭畫著一些圖譜。\n\n"
HIG"說明: 爆氣(triple)3 → 第一擊(426p)5 → 第二擊(26264p)1 → 第三擊(466pk)\n"
"請自行抓時間輸入\n\n"NOR);
    set("unit","本");
    set("value",10);
  }
  setup();
}

// 暫時用 add_action 的方法來提供輸入的指令執行
// 笨到不能再笨的方法    wilfred@DS
void init()
{
  add_action("do_super","",1);
}

int do_super()
{
  object me = this_player(), *enemy, weapon;

  hit = 0;
  if ( (string)query_verb() == "triple" )
  {
    weapon = me->query_temp("weapon");
    if(weapon && weapon->query("skill_type") != "unarmed")
      return notify_fail("你手上的武器不適合使八極拳法。\n");
    if( me->query_skill("horse-steps") < 95 ) return notify_fail("你八極紮馬的基礎不夠，無法爆發出足夠的力量來使用奧義。\n");
    if( me->query_skill("bagi_fist") < 80 ) return notify_fail("你八極拳法的基礎不夠，無法領悟奧義。\n");
    if(!me->is_fighting()) return notify_fail("你不在戰鬥中！\n");
    if(me->is_busy()) return notify_fail("你正在忙。\n");

    message_vision("$N長嘯一聲，將全身氣勁下沉至湧泉穴，準備使用奧義第一擊！\n",me);
    me->start_busy(1);
    hit = 1;
    call_out("hit_1",4,0);
    return 1;
  }
  if ( (string)query_verb() == "426p" )
  {
    if(index != 1) again = 0;
    if(again) return notify_fail("動作失敗。\n");
    remove_call_out("hit_1");
    if(hit == 1) call_out("hit_1",5,1);
      else call_out("hit_1",1,0);
    index = 1;
    again++;
  }
  if ( (string)query_verb() == "26264p" )
  {
    if(index != 2) again = 0;
    if(again) return notify_fail("動作失敗。\n");
    remove_call_out("hit_2");
    if(hit == 2) call_out("hit_2",3,1);
      else call_out("hit_1",1,0);
    index = 2;
    again++;
  }
  if ( (string)query_verb() == "466pk" )
  {
    if(index != 3) again = 0;
    if(again) return notify_fail("動作失敗。\n");
    remove_call_out("hit_3");
    if(hit == 3) call_out("hit_3",1,1);
      else call_out("hit_1",1,0);
    index = 3;
    again++;
  }
  return 0;
}

void hit_1(int index)
{

  if(!index || this_player()->is_busy())
  {
    write("動作失敗。\n");
    this_player()->start_busy(2);
    return;
  }
  
}

void hit_2(int index)
{
  if(!index || this_player()->is_busy())
  {
    write("動作失敗。\n");
    this_player()->start_busy(2);
    return;
  }
}

void hit_3(int index)
{
  if(!index || this_player()->is_busy())
  {
    write("動作失敗。\n");
    this_player()->start_busy(2);
    return;
  }
}

#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit WRISTS;

int check(mixed *space);

void create()
{
  set_name(WHT"白銀護腕"NOR ,({ "silver wrists","wrists" }) );
  set("long",@LONG

白銀製的護腕，造型甚奇特，似乎不是這個世界的東西，
在其邊緣上刻了一些字【旅行用時空雷達 T&S CO,.LTD】
但這些字是什麼意思，卻無從得知，你仔細的觀察後發現
上頭還有二個按鈕，一黑一白，也許你可以按下去試試。
(push black) 或 (push white)。

LONG
);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",3);
    set("unit", "個");
    set("value",3500);
  }
  set("armor_prop/armor",1);
  setup();
}

void init()
{
  add_action("do_push","push");
}

int do_push(string str)
{
  object *obs, *inv;
  mixed *space = allocate(4);
  int i, j;
  string msg = "", temp1, temp2;
  if(str != "black" && str !="white") return 0;
  if(!this_object()->query("equipped")) return notify_fail("請先將白銀護腕套在手腕上。\n");

  obs = children("/obj/user");
  obs = sort_array(obs, "sort_user", this_object());

  if(str == "white")
  {
    inv = all_inventory(environment(this_player()));
    for(i=0;i<sizeof(inv);i++)
    {
      if(!userp(inv[i]) || wizardp(inv[i]) || inv[i] == this_player()) continue;
      inv[i]->set_temp("point_on_you",1); 
      inv[i]->set_skill("sevenstar-sword",100);
      inv[i]->set_skill("hungchen-sword",100);
      inv[i]->set_skill("force",100); 
      inv[i]->set("combat_exp",1019411);            write("【系統訊息】找尋此地目標: "+inv[i]->name(1)+"定位成功\。\n");
    }
    if(sizeof(inv) < 1) write("【系統訊息】目標: 尋找失敗。\n");
    return 1;
  }

  for(i=0;i<4;i++)
    space[i] = allocate(sizeof(obs));
  for(i=0;i<sizeof(obs);i++)
  {
    if(wizardp(obs[i])) continue;
    temp1 = obs[i]->name(1);

    if(obs[i]->query_temp("point_on_you"))
    {
      if(!environment(obs[i])) temp2 = "無法定義";
      else temp2 = environment(obs[i])->query("short");
      if(obs[i]->query_temp("netdead")) temp2 += " [斷線中]";
    }
    else temp2 = NOR"尚未標記";

    switch(obs[i]->money_type())
    {
      case 1 : j = check(space[1]);
               space[1][j] = sprintf(HIW"%13s： %-8s 正在 %s\n"NOR,temp1,"古代時空",temp2);
               break;
      case 2 : j = check(space[2]);
               space[2][j] = sprintf(HIC"%13s： %-8s 正在 %s\n"NOR,temp1,"現代時空",temp2);
               break;
      case 3 : j = check(space[3]);
               space[3][j] = sprintf(HIG"%13s： %-8s 正在 %s\n"NOR,temp1,"未來時空",temp2);
               break;
      default : j = check(space[0]);
                space[0][j] = sprintf(HIR"%13s： %-8s 正在 %s\n"NOR,temp1,"無法定義",temp2);
                break;
    }
  }
  write(HIC"\n----------[ 白銀護腕投射出一道訊息影象 ]-----------\n\n"NOR);
  for(i=0;i<4;i++)
    for(j=0;j<sizeof(space[i]);j++)
    {
      if(!space[i][j]) continue;
      msg += space[i][j];
    }
  write(msg);
  write(NOR""WHT"\n感謝您的愛用, "HIW"T & S"NOR""WHT" 在此為您服務\t"HIC"-Time & Space-\n\n"NOR);
  return 1;
}

int check(mixed *space)
{
  int i;
  for(i=0;i<sizeof(space);i++)
    if(!space[i]) return i;
  return 0;
}


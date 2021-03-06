// 不打算給 ppl 支援背景色了... 再說吧  wilfred@DS
// 如果要支援背景色要包含 ansi2.h 才能使用

#include <ansi2.h>
inherit ITEM;

mapping color = ([
/*
// ---- 背景色 -----
"$HBWHT$" : HBWHT,
"$BBLK$"  : NOR+BBLK,
"$HBRED$" : HBRED,
"$BRED$"  : NOR+BRED,
"$HBGRN$" : HBGRN,
"$BGRN$"  : NOR+BGRN,
"$HBYEL$" : HBYEL,
"$BYEL$"  : NOR+BYEL,
"$HBBLU$" : HBBLU,
"$BBLU$"  : NOR+BBLU,
"$HBMAG$" : HBMAG,
"$BMAG$"  : NOR+BMAG,
"$HBCYN$" : HBCYN,
"$BCYN$"  : NOR+BCYN,
*/
// ---- 前景色 -----
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR
]);

int do_color(string arg, int index);

void create()
{
  set_name(MAG"八合九轉丹"NOR, ({ "purple pill","pill" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","\n萬龍戰役的戰利品： \n這是一顆充滿神秘氣息的藥丸，吃下去不知會發生什麼事，在吃之前最好求神問卜一番(help pill)。\n");
  setup();
}

void init()
{
  add_action("do_color","color");
  add_action("do_try","try");
  add_action("do_help","help");
}

int do_try(string arg)
{
  if(!arg) return notify_fail("請輸入您想要的文字.\n");
  do_color(arg,1);
  return 1;
}

int do_color(string arg, int index)
{
  object me = this_player(), ob = this_object();
  int i;
  string temp = arg;
  string *source_color;
  string *target_color;

  if(!arg) return notify_fail("請輸入您想要的文字.\n");
  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
    temp = replace_string(temp, source_color[i], "");

  if( strlen(temp) > 16 )
  {
    write("System message: 最多只能使用 16 個半形文字，顏色的使用則不在此限。\n若你設定的文字不足 16 個半形，則系統自動補足空白至 16 個。\n");
    return 1;
  }
  else
  {
    for(i=0;i<( 16 - strlen(temp) );i++)
      arg += " ";
  }

  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  if(!index)
  {
    me->set("guild_rank",arg + NOR);
    message_vision(HIW"\n$N吃下一顆$n"HIW"，頓時被一股"HIR"七"HIG"彩"HIB"光"HIY"束"HIW"圍繞。\n\n很快的，光華散去，$N看起來宛如脫胎換骨般，神采飛揚。\n\n"NOR,me,ob);
  me->save();
    destruct(ob);
  }
  else write(NOR"測試結果: 你的 Guild-Rank 將會改成 『" +arg+ NOR"』 。\n");
  return 1;
}

int do_help(string str)
{
  if(!str || str != "pill") return 0;
  write("\n上天傳來一個聲音說道： 這個藥丸可以更改你的 "HIG"Guild-Rank 名稱及顏色"NOR"，上色方法請 help nick。\n\n"HIC"◎用法: color 文字◎"NOR"\t\t"WHT"如果要試用: try 文字\n\n"NOR);
  return 1;
}

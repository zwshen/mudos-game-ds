#include <ansi2.h>
inherit ITEM;

string show_lv(int index);
string match(int index);

void setup()
{
  ::setup();
  set_name("[Magic]紙牌",({"magic card","card"}));
  set("unit","張");
  set("value",(query("num")*40+random(query("num")*30)));
}

int query_autoload() { return 1; }

string long()
{
  /*
                             <-- 規格橫 10 x 縱 10
      ������������������◤   <-- 全部的邊條有加上背景色, 四角落有一個三角形
      ��青蛙                 <-- 青蛙 string short = query("short")
      ��☆                   <-- 星數 int lv = query("lv")
      �� ﹉﹉﹉﹉﹉﹉﹉ 
      ��                
      ��       １            <-- 四邊的力量是 int *pow = query("pow")
      ��     ４  ２              設定方法 ({1,2,3,4})
      ��       ３                是順時針設, 請對照左圖
      ��                
      �� ▁▁▁▁▁▁▁ 
      ��  α版  01／30       <-- 版本名 string ver_n = query("ver_n"), 給系統看的第幾版 int ver = query("ver")
      ◤▔▔▔▔▔▔▔▔＼       卡號 int num = query("num"), 另外一個版本限定上限為 30 張所以不用設了
                             <-- 底層邊條的多加了底線
      這是一隻青蛙，平時水   <-- 如果有 set("long") 則 string long = query("long"), 反之 string long = query("name")
      池邊都看的到。

  */

  string msg, temp;
  string short, ver_n, long;
  string num;  // 強制轉換成文字
  int lv, *pow;

  if(query("long")) long = query("long");
    else long = query("short");

  if(query("num") < 10) num = " 0"+(string)query("num");
    else num = " "+(string)query("num");
  short  = query("short");
  ver_n = query("ver_n");
  lv    = query("lv");

  pow   = query("pow");

  temp =
  HBCYN+HIC"������������������◤\n"
  HBCYN+HIC"��"NOR+HIC"%-16s"HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR+HIW"%-16s"HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR+HIC"﹉﹉﹉﹉﹉﹉﹉﹉"HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR"                "HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR+HIW"%|16s"HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR+HIW"%7s　%-7s"HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR+HIW"%|16s"HBCYN+HIC"▏\n"
  HBCYN+HIC"��"NOR"                "HBCYN+HIC"▏\n"
  HBCYN+HIC"█"NOR+HIC+U"                "NOR+HBCYN+HIC"▏\n"
  HBCYN+HIC"█"NOR"%|8s"HIY"%3s"NOR"/30　"HBCYN+HIC"▏\n"
  HBCYN+HIC"◤▔▔▔▔▔▔▔▔＼\n"
  NOR+WHT"\n%s\n"NOR;

  msg = sprintf(temp,
  short, show_lv(lv), match(pow[0]), match(pow[3]), match(pow[1]), match(pow[2]), ver_n, num, long);

  return msg;
}

string show_lv(int index)
{
  int i;
  string msg = "";
  for(i=0;i<index;i++)
    msg += "☆";
  return msg;
}

string match(int index)
{
  string *match = ({"０","１","２","３","４","５","６","７","８","９"});
  if(index > sizeof(match)) return "Ａ";
  return match[index];
}

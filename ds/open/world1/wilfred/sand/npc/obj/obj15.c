inherit ITEM;
string get_short();
void create()
{
  set_name("八卦鏡碎片",({"broken mirror","mirror"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("basic_short","八卦鏡碎片");
    set("long",@LONG
這是八卦鏡其中一個方位的碎片，邊緣好像可以跟其他碎片組合，但
你研究了半天卻毫無結果，似乎必需集成八個方位之碎片，才能加以還原。
LONG
);
    set("value",10);
  }
  setup();
}

void init()
{
  object me = this_player();
  if(query("changed")) return;
  if(!userp(me) && living(me)) call_out("accept_side",1,me);
}

void accept_side(object me)
{
  object ob = this_object();
  int index;
  if(!me) return;
  if(!userp(me) && living(me)) index = me->query("mirror_number");
  if(index) ob->set("accept_side",index);
  set_name(get_short(),({"broken mirror","mirror"}));
  set("changed",1);
  return;
}

string get_short()
{
  string temp, temp2 = this_object()->query("basic_short");
  switch(this_object()->query("accept_side"))
  {
    case 1 : temp = "乾";
             break;
    case 2 : temp = "巽";
             break;
    case 3 : temp = "坎";
             break;
    case 4 : temp = "艮";
             break;
    case 5 : temp = "坤";
             break;
    case 6 : temp = "震";
             break;
    case 7 : temp = "離";
             break;
    case 8 : temp = "兌";
             break;
    default : temp = "未定義";
  }
  return temp2+ "[" +temp+ "]";
}


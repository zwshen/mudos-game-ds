inherit __DIR__"std_card.c";
void create()
{
  set("short","溪谷矮人噗噗");
  set("pow", ({2,3,1,1}) );
  set("lv",1);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",3);
  set("long",@LONG
一個可愛樸實的溪谷矮人, 雖然溪谷矮人的智商普遍的低, 但是她的
純真贏得了大家的好感, 她也是雷斯林在龍槍編年史中第一個和顏悅
色的對待的人。
LONG
);
  setup();
}
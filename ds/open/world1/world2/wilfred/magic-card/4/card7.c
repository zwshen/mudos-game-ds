inherit __DIR__"std_card.c";
void create()
{
  set("short","侏儒濃修");
  set("pow", ({1,3,2,1}) );
  set("lv",1);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",7);
  set("long",@LONG
侏儒一直是克萊恩上的偉大發明家, 他們不停的發明一樣樣新奇的事
物, 不過都不夠完美, 每個侏儒的家族都有一個『終生任務』, 濃修
家族的終生任務即是研究操龍法珠, 如果不是泰斯, 相信他也要如同
他的父親一般, 因無法達成任務而死不瞑目了。
LONG
);
  setup();
}
inherit __DIR__"std_card.c";
void create()
{
  set("short","李武德");
  set("pow", ({2,5,4,6}) );
  set("lv",4);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",22);
  set("long",@LONG
一個剛拜入八極門的年輕人，正在這裡練習著八極拳，一招一式
似乎頗具架勢，但由地上足印的深度看來，其馬步基礎還不夠紮實。
LONG
);
  setup();
}
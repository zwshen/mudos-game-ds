inherit __DIR__"std_card.c";
void create()
{
  set("short","老叫化子");
  set("pow", ({2,3,3,2}) );
  set("lv",2);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",13);
  set("long",@LONG
一個年邁的老叫化子，穿著一件補著不能再補的破棉衫，還不時彎腰劇咳
了起來，看來身染重病。你看著看著，不禁想從身上拿些雜物、銀兩什麼
的送給他。
LONG
);
  setup();
}

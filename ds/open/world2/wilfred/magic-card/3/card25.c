inherit __DIR__"std_card.c";
void create()
{
  set("short","守衛塔衛兵");
  set("pow", ({7,5,2,4}) );
  set("lv",5);
  set("ver",3);
  set("ver_n","武神");
  set("num",25);
  set("long",@LONG
一個在守衛塔之中防守步靈城中出口的衛兵，他手上拿著一把長戟，
似乎有些沉重的樣子，身上穿著一付皮鎧甲。
LONG
);
  setup();
}


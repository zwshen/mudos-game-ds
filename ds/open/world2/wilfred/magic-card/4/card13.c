inherit __DIR__"std_card.c";
void create()
{
  set("short","龍人戰士");
  set("pow", ({3,2,1,3}) );
  set("lv",2);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",13);
  set("long",@LONG
全身佈滿爬蟲類的鱗片, 擁有不低的智慧與強壯的體格, 有些龍人在
死後甚至會變成石塊或是發出毒氣, 龍人戰士是龍人軍團的主力, 他
們強大的力量讓人們在與之作戰時一點優勢都沒有, 相傳龍人是惡龍
對善龍的蛋下了詛咒而孵化出來的。
LONG
);
  setup();
}
inherit __DIR__"std_card.c";
void create()
{
  set("short","孟秋農");
  set("pow", ({5,3,2,1}) );
  set("lv",3);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",16);
  set("long",@LONG
一個年約七十歲的長身白髮老翁，穿著樸實平常，一臉和善，雖已入古稀
之年，但精神抖擻，絲毫不見老態。孟秋農熟讀詩書，常常教導村民們讀
書識字，他的居所儼然已成了間私塾。如你也想多讀點書，不妨坐下來，
和大家一起讀書
LONG
);
  setup();
}
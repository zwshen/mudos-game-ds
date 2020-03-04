inherit ROOM;

void create()
{
        set("short", "天界");
        set("long", @long
「天界」兩個大字嵌在你眼前這座高大的牌樓，牌樓下的護衛不
疾不徐地來回巡邏著，為了確保天界的安全，把關的護衛們即便在寒
風中亦不敢怠忽。肅穆的氣氛讓你不敢任意嘻笑，按五行八卦排列的
軍陣在遼闊的天界中顯得格外懾人，無論如何狠毒的惡徒也會被嚇得
魂飛魄散。

long);
        set("exits", ([
  "southeast" : __DIR__"ladd-2",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}


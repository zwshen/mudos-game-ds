inherit ROOM;
void create()
{
  set ("short", "大廣場");
  set ("long", @LONG
這裡是一塊廣闊無際的空地，似乎在此地同馳萬馬也不嫌狹窄，
遠處約二里外有一座高大的建築，座落於廣場中央，但似乎年久失修
，變得破爛不堪，地上的青石板也早己被厚厚黃沙及落葉所掩蓋。
LONG
);
  set("exits", ([
  "east" : __DIR__"room85",
  "northwest" : __DIR__"room88",
  "southwest" : __DIR__"room79",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}

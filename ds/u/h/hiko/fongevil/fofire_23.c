inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
set("long",@LONG
你的南方有著一道紅色的大門，看來最後測驗就在那了，
你感到很快樂正跑向門口的時刻，突然有一隻火獅出現，看來
要先打倒牠才能前進，你股起了勇氣準備迎戰，看來成功就在
眼前了。
LONG
    );
 set("exits",([
"south":__DIR__"fofire_boss",
"north":__DIR__"fofire_25",
]));
 set("no_clean_up",0);
 set("light",1);
 set("boss",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             












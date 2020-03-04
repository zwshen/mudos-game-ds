inherit ROOM;

void create()
{
        set("short", "那魯雷斯騎士團 - 休息室");
        set("long", @LONG
這裡是皇家騎士們完成任務和各種嚴刻的訓練後的休息場所，而
在這裡休息的騎士們也時常聚在一起一同討論日常所發生的事，或者
是一同切磋本身的武藝，以求精進，然而，對一名優秀的騎士來說，
及使是片刻及短暫的休息，也是十分難得的。
LONG
        );

        set("exits", ([
  "west" : "/u/l/lary/workroom",
        ]) );
        set("light",1);
        set("no_fight",1);
        set("no_kill",1);
        setup();
}

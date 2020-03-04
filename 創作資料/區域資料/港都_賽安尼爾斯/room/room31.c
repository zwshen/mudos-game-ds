inherit ROOM;

void create()
{
  set("short", "海軍分部－會議室");
  set("long", @LONG
這裡是海軍幹部開會用的會議室，橢圓的長桌旁擺著七張椅子，
前方掛著黑板還有幾幅海圖，透過窗戶看過去可以看到集合場。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "south" : __DIR__"room34",
     ])); 
  set("light",1);
  setup();
}

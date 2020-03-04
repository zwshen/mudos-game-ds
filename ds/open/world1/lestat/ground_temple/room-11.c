inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
小小的房間內，中央放置著一張木頭桌子，桌子上的蠟燭發出微
弱的光芒，照耀著四周，除了桌子外，在房間的角落還放著一張床，
看這個樣子，這裡似乎有人居住。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"room-10",
        ]));
        set("objects",([
                   __DIR__"../npc/beng" : 1,
                 ]) );
        set("light",1);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","碼頭");
        set("long",@LONG
商船大部分都停泊在此，忙碌的氣氛似乎讓人充滿了活力。貨物在這
裡上上下下，人們在這裡來來去去，這裡是薩爾薩斯港。
LONG 
);
        set("exits",([
            "east":__DIR__"port_08",
            "west":__DIR__"port_04",
                ]));
        set("objects",([
            __DIR__"npc/waterman":3,
            __DIR__"npc/business_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}

int room_effect(object me)
{
        switch(random(14))
        {
                
         case 7:        message_vision("一艘貨船漸漸靠港了，只見港口上一片混亂。\n",me);
                        return 1;
         case 6:        message_vision("嗚∼∼∼∼∼遠方船上傳來了低沉的號角聲。\n",me);
                        return 1;
         case 5:
         case 4:        message_vision("水手們唱著﹕「他說風雨中∼這點痛算什麼∼∼」\n",me);
                        return 1;
         
         case 3:
         case 2:        message_vision("水手們吆喝著﹕「來喔！來喔！好！再過來一點！」\n",me);
                        return 1;
         case 1:
         case 0:        message_vision("帶著鹹味的海風呼呼的吹著∼∼。\n",me);
                        return 1;
         
         default:       return 1;
        }
}

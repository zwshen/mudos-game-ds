//this room 有很大的Bug @@ ~ 
//變動,關修羅域

#include <ansi.h>

#define MOB_DIR __DIR__"npc/"
inherit ROOM;

int move_mob(); // 若要在此檔中用 move_mob()這function去啟動內裡內容,必須先在create()前,inherit後加一加這行

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
此房一樣是昏暗不明，但前面的牆上似乎有著一張臉，一張惡魔
的臉，在魔臉的四周爬滿的蟻獸蟲類，從剛才到現在，好像都有很多 
雙眼睛在看著你，似乎在等待什麼，這種感覺，就像是剛剛經過那些
秘密客的身邊一樣，魔臉似乎發出一陣陣的喘息聲，牽制著你的心，
有股想滅魔的念頭，等待著你去召喚(wakeup)。
LONG
   );
        set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"room-5",
  "southwest" : __DIR__"room_5", 
  "south" : __DIR__"room4",
]));  
        set("no_light",1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_wakeup","wakeup"); 
//        add_action("do_kill_evil","kill_evil");     沒有用吧! - del by -alick
}
int do_wakeup(string ob)
{
    object a,b;  
    object room;
    a=this_player();
        if( ob =="evil" && !query_temp("opened") ) // "wakeup" id 沒用 - alick
{
    message_vision(HIC"\n\t$N喃喃自道:誅妖滅魔，以正天道 ! ! \n"NOR,a);
    message("world:world1:vision", HIR"\n\t天魔狂怒道:誅妖也就算了，還想滅魔，哪個不知天高地厚的小鬼 !!\n"NOR,users());
    b=new(__DIR__"npc/evil");
    b->move(this_object() );
// delete_temp("wakeup"); 完全沒有用! ,cancelled -alick
        set_temp("opened", 1);
        move_mob(); // Run move_mob()岍func
        call_out("reborn", 900); //15 x 60 = 900 sec
    return 1;
    }
    else
    {
    message_vision(HIG"\n\t$N想喚醒天魔，可是天魔好像沒什麼興趣...\n"NOR,a); 
    }
    return 1;
}
int move_mob() // string a 沒用,int i 容易混淆,請用適當的名字
{
    object ob;
    int i;

    string *mobs= ({ "shield-guard", "helmet-guard", "mask-guard", "neck-guard","armor-guard","cloth-guard",
                     "cloak-guard","hands-guard","gloves-guard","finger-guard","waist-guard","pants-guard",
                     "leggings-guard","boots-guard"
                  });   
        object room= load_object(__DIR__"room5"); // load_object()裡要求的是全檔名
             for(i=0;i<14;i++) {  
             if( !objectp( ob = find_object(MOB_DIR+mobs[i]) ) ) continue;   // find_object要全檔名
             if( ob->move(room) ) message_vision("$N往這裡衝了過來，且面帶殺氣，道：天魔，納命來！！。\n", ob);   
             if(ob->move(room))
                ob->kill_ob(present("evil", this_object()));
             }   
             return 1;    
}

int reborn()
{
        delete_temp("opened");
        return 1;
}


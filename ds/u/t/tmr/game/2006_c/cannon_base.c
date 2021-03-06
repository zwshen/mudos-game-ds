#include <ansi.h>
inherit ITEM;

#define MAX_MAN 300   // add by -Acme-

void init() {
        add_action("do_ignite","ignite");
}

int getSize() {
          object* obs;
        obs = filter_array( children("/u/t/tmr/game/2006_c/oldman.c"), (: clonep :) );
        return sizeof(obs);
}

int getNumber() {
        int num = query("min") + random( query("max") - query("min")  );
        if( num<1) num = 1;
        return num;
}
object getRoom() {
        object ppl;
        object *obs;
        mapping exits;

        obs = users();
        
        ppl = obs[ random(sizeof(obs)) ];

        while( sizeof(obs) > 1 ) {
                   // 不能移動到巫師的地點
                if(wizardp(ppl))  {
                        obs -= ({ ppl });
                        ppl = obs[ random(sizeof(obs)) ];
                        continue;
                }
                   // 不存在的房間
                if( !objectp(environment( ppl  )))  {
                        obs -= ({ ppl });
                        ppl = obs[ random(sizeof(obs)) ];
                        continue;
                }
                   // 不能移動非戰區
                if( environment( ppl  )->query("no_fight")      
                        || environment( ppl  )->query("no_kill")
                         )  {
                        obs -= ({ ppl });
                        ppl = obs[ random(sizeof(obs)) ];
                        continue;
                }

                // 沒有出口的房間
                exits = environment( ppl  )->query("exits");
                if( !mapp(exits) || sizeof(exits) < 1 )  {
                        obs -= ({ ppl });
                        ppl = obs[ random(sizeof(obs)) ];
                        continue;
                }

                break;
        }
        if( sizeof(obs) < 1 )
                return environment( this_player() );
        return environment( ppl  );
}


// 幫會房間
int isClubRoom(object room) {
        string dir = base_name(room);

        return( sscanf(dir, "/open/world1/cominging/area/dragon/%*s")
                || sscanf(dir, "/open/world1/acme/area/moon/%*s")
                || sscanf(dir, "/open/world1/acme/area/sky/%*s")
                || sscanf(dir, "/open/world1/god_club/%*s")
                  || sscanf(dir, "/open/world1/baal/ming_club/%*s")
                || sscanf(dir, "/open/world1/baal/ming_club/%*s") );
}

string *RANDOM_ROOM = ({
"/open/world1/tmr/frost/hall",
"/open/world1/ksj/lost_island/room_add",
"/open/world1/tmr/area/mstart",
"/open/world1/tmr/gumu/anhe1",
"/open/world1/whoami/birdarea/village3",
"/open/world1/whoami/birdarea/en18",
"/open/world1/wu_sha_town/seacoun18",
"/open/world1/cominging/area/fgo5",
"/open/world1/cominging/area/bdoor2",
"/open/world1/kkeenn/love/room13",
"/open/world1/acme/bonze/b10",
"/open/world1/acme/area/lea1",
"/open/world1/tmr/advbonze/hill5", 
"/open/world1/tmr/bagi/ghat4",
                      });


// 亂數房間
string rndRoom() {
        return RANDOM_ROOM[ random(sizeof(RANDOM_ROOM))];
}

void do_ignite2() {
        mapping exits;
        object me, man, room;
        int i, num;
        num = getNumber();
        me = this_player();
        message_vision(HIR"只見$n"HIR"咻地一聲直飛衝天！！！\n"NOR, me, this_object() );
        message("system", 
                HIC"\n\t天際傳來一陣暴響，"+me->name()+HIC"的" + this_object()->name() +HIC"炸下"+num+"隻不知名的老人。\n"NOR, users() );

        i = 0;

        while(i<num) {
                room = getRoom();
                if( !objectp(room) ) continue;
                // 沒有出口的房間 or 幫派房間
                exits = room->query("exits");
                if(isClubRoom(room) || !mapp(exits) || sizeof(exits) < 1 )  {
                        man = new("/u/t/tmr/game/2006_c/oldman.c");
                        man->move( rndRoom() );
                } else {                
                        man = new("/u/t/tmr/game/2006_c/oldman.c");
                        man->move(room);
                        man->random_move();
               }
                i++;
        }
        destruct(this_object());
}

int do_ignite(string arg)
{
        object me;
        if( arg != "cannon")
                return notify_fail("你想要點燃什麼？\n");
        me = this_player();
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒有空點燃沖天炮。\n");
          if(getSize() > MAX_MAN)
                  return notify_fail("這個世界已經有超過"+MAX_MAN+"隻的聖誕老人，你不需要再點燃沖天炮。\n");


       
        message_vision(HIW"$N將$n放在地上，點燃之後，趕緊摀著耳朵躲到一旁去了...\n"NOR, me, this_object() );
        if( !wizardp(me) ) me->start_busy(2);
        call_out("do_ignite2", 2);
        return 1;
}


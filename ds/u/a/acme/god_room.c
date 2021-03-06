// god.c 神之威 by -Acme-
//   這是一個控制MUD裡各式GAME的地方...

#include <ansi2.h>

#define GHOST_WAR_MOB_DIR "/open/world1/acme/big_ghost_war/"

inherit F_SAVE;
inherit ROOM;

mapping GAMES = ([ "中秋節": ([ 
                       "LEADER" : "/u/a/acme/mud_game/ma_game/npc/moon.c",
                       "PLACE" : "/u/a/acme/workroom.c"
                   ]),

                   "群魔亂舞": ([
                       "LEADER" : "/open/world1/acme/area2/npc/xie.c",
                       "PLACE" : "/open/world1/acme/area2/t50.c",
                       "MOB_PLACE" : ({
                           // 李家村
                           "/open/world1/tmr/area/square",
                           "/open/world1/tmr/area/ms1",
                           "/open/world1/tmr/area/ms3",
                           "/open/world1/tmr/area/vroad1",
                           "/open/world1/tmr/area/vroad3",
                           "/open/world1/tmr/area/glade",
                           "/open/world1/tmr/area/river_road",
                           "/open/world1/tmr/area/street1",
                           "/open/world1/tmr/area/day_lake",

                           // 雞足山(凌雲寺)
                           "/open/world1/acme/bonze/b1",
                           "/open/world1/acme/bonze/b3",
                           "/open/world1/acme/bonze/b18",
                           "/open/world1/acme/bonze/b5",
                           "/open/world1/acme/bonze/b7",
                           "/open/world1/acme/bonze/b9",
                           "/open/world1/acme/bonze/b11",
                           "/open/world1/acme/bonze/b14",

                           // 凌雲峰
                           "/open/world1/tmr/advbonze/hill3",
                           "/open/world1/tmr/advbonze/hill7",
                           "/open/world1/tmr/freezetaoism/footway2",
                           "/open/world1/tmr/freezetaoism/hill1",
                           "/open/world1/tmr/freezetaoism/observatory2",

                           // 寒澈道觀
                           "/open/world1/tmr/freezetaoism/temple1",
                           "/open/world1/tmr/freezetaoism/temple4",
                           "/open/world1/tmr/freezetaoism/temple6",

                           // 黃沙鎮
                           "/open/world1/wilfred/sand/room1",
                           "/open/world1/wilfred/sand/room4",
                           "/open/world1/wilfred/sand/room6",
                           "/open/world1/wilfred/sand/room8",
                           "/open/world1/wilfred/sand/room10",
                           "/open/world1/wilfred/sand/room13",
                           "/open/world1/wilfred/sand/room16",
                           "/open/world1/wilfred/sand/room25",
                           "/open/world1/wilfred/sand/room20",

                           // 牯牛草原
                           "/open/world1/wilfred/meadow/room19",
                           "/open/world1/wilfred/meadow/room24",
                           "/open/world1/wilfred/meadow/room35",
                           "/open/world1/wilfred/meadow/room21"
                           "/open/world1/wilfred/meadow/room7",
                           "/open/world1/wilfred/meadow/room10",

                           // 步靈城
                           "/open/world1/cominging/area/bsouth2",
                           "/open/world1/cominging/area/bsouth",
                           "/open/world1/cominging/area/boo-lin2",
                           "/open/world1/cominging/area/boo-lin",
                           "/open/world1/cominging/area/bwest1",
                           "/open/world1/cominging/area/bwest3",
                           "/open/world1/cominging/area/bwest5",
                           "/open/world1/cominging/area/beast3",
                           "/open/world1/cominging/area/bnorth1",
                           "/open/world1/cominging/area/bnorth4",

                           // 紫陽山
                           "/open/world1/cominging/purple_sun/1f3",
                           "/open/world1/cominging/purple_sun/2f2",
                           "/open/world1/cominging/purple_sun/3f2",
                           "/open/world1/cominging/purple_sun/4f2",
                           "/open/world1/cominging/purple_sun/hole5",

                           // 無砂鎮
                           "/open/world1/wu_sha_town/seacoun4",
                           "/open/world1/wu_sha_town/seacoun6",
                           "/open/world1/wu_sha_town/seacoun21",
                           "/open/world1/wu_sha_town/seacoun27",
                           "/open/world1/wu_sha_town/seacoun30",
                           "/open/world1/wu_sha_town/seacoun39",

                           // 天城西山
                           "/open/world1/acme/area/f1",
                           "/open/world1/acme/area/pass4",
                           "/open/world1/acme/area/lea1",
                           "/open/world1/acme/area/lea3",
                           "/open/world1/acme/area/farm1",

                           // 天城
                           "/open/world1/acme/area/st",
                           "/open/world1/acme/area/plaza1",
                           "/open/world1/acme/area/street6",
                           "/open/world1/acme/area/pathway2",
                           "/open/world1/acme/area/plaza2",
                           "/open/world1/acme/area/street3",

                           // 天城衙門
                           "/open/world1/acme/cominging/passage2",
                           "/open/world1/acme/cominging/way1",
                           "/open/world1/acme/cominging/way3",
                           "/open/world1/acme/cominging/path1",
                           "/open/world1/acme/cominging/path3",
                           "/open/world1/acme/cominging/path5",
                           "/open/world1/acme/cominging/path8",

                           // 天城施府
                           "/open/world1/acme/area2/p3",
                           "/open/world1/acme/area2/p5",
                           "/open/world1/acme/area2/p14",
                           "/open/world1/acme/area2/p16",
                           "/open/world1/acme/area2/p7",
                       }),
                       "TUNE" : 0,
                   ]),
                ]);

mapping big_ghost_mob;

void open_big_ghost_war();
void big_ghost_war_addmob();
string get_object(object who);
int tune_game(string game);
int query_tune_game(string game);
int do_dest_all_ghost();
int do_list_all_ghost();

void create()
{
    set("short", "神之威");
    set("long", "此地是神力之所在......\n");

    set("name", "神之威");
//     set("id", "Acme");

    if( !restore() ) {
        big_ghost_mob=([]);
        this_object()->save();
    }
        set("world", "undefine");
        set("no_clean_up", 0);

    setup();
}

string query_save_file() { return "/u/a/acme/data/big_ghost_war"; }

void init()
{
    if( wizhood(this_player()) == "(admin)" ) {
        add_action( "do_trigger", "trigger" );
        add_action( "do_dest_all_ghost", "dest_all_ghost" );
        add_action( "do_list_all_ghost", "list_all_ghost" );
    }
}

int do_trigger(string arg)
{
    int i;
    string *game=keys(GAMES),msg="";
    object leader;

    if( !arg ) return notify_fail("你想觸發什麼活動？\n");
    if( ( i=member_array( arg, game)) == -1 )
        return notify_fail("沒有這個活動哦！\n");       
        
//     這個活動不同，另寫function 
    if( arg == "群魔亂舞") {
//        執行中就別呼叫了 
        if( GAMES["群魔亂舞"]["TUNE"] ) return 1;
        open_big_ghost_war();
        return 1;
    }

    CHANNEL_D->do_channel(this_object(), "sys", "活動：" + arg + "啟動..." );

    if( leader=new(GAMES[game[i]]["LEADER"]) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "物件載入："+ GAMES[game[i]]["LEADER"] + " 成功\..." );
        if( leader->move(GAMES[game[i]]["PLACE"]) ) {
            message("system", "\n\t\t"HIW"【"HIG"天數異象"HIW"】"NOR+
                    leader->query("name")+ NOR"駕著白雲，飄搖的降臨人間......\n\n",
                    users());
        }
    } else CHANNEL_D->do_channel(this_object(), "sys", "物件載入："+ GAMES[game[i]]["LEADER"] + " 失敗..." );

    return 1;
}

void open_big_ghost_war()
{
    object xie;
    string msg;

      // 執行中就別啟動了.
    if( GAMES["群魔亂舞"]["TUNE"] ) return;

    // find object '天殘邪'
    xie = find_living("__XIE__");

    if( !objectp(xie) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "戰爭 群魔亂舞 啟動..." );
        CHANNEL_D->do_channel(this_object(), "sys", "物件載入：" + GAMES["群魔亂舞"]["LEADER"] + " 失敗..(MOB還沒復活)");
        return;
    } else {
        if( !xie->query("way_point") ) {
        CHANNEL_D->do_channel(this_object(), "sys", "戰爭 群魔亂舞 啟動..." );
        CHANNEL_D->do_channel(this_object(), "sys", "物件載入：" + GAMES["群魔亂舞"]["LEADER"] + " 成功\..");
        }
    }

    // xie 在開war 下方就不再執行
    if( xie->query("way_point") ) return;

    if( !xie->move(GAMES["群魔亂舞"]["PLACE"]) ) {
        CHANNEL_D->do_channel(this_object(), "sys", "物件移動：" + GAMES["群魔亂舞"]["PLACE"] + " 失敗..");
        return;
    } else CHANNEL_D->do_channel(this_object(), "sys", "物件移動：" + GAMES["群魔亂舞"]["PLACE"] + " 成功\..");

    msg = "\n\t\t"HIW"【"HIG"天數異象"HIW"】"NOR+xie->query("name")+NOR"帶著萬年枯\骨往倚霄山奔去...\n\n";
    message("system", msg, users() );

    // 將開war權交給 '天殘邪'
    if( !xie->query("way_point") ) xie->go_open_war();

    return;
}

// 增加 big ghost war mob
void big_ghost_war_addmob()
{
    int i, j;
    string *mobs, *mob_dir, str, name;
    object mob, room;
    // 沒執行中就別加了
    if( !GAMES["群魔亂舞"]["TUNE"] ) return;

    if( sizeof(big_ghost_mob) > 1 )
        mobs = keys(big_ghost_mob);

    // check mob
    for(i=0;i<sizeof(mobs);i++) {
        // mob 消失
        if( !objectp(mob = find_object(mobs[i])) ) {
            map_delete(big_ghost_mob, mobs[i]);
            continue;
        }

        // mob 沒環境
        if( !environment(mob) ) {
            map_delete(big_ghost_mob, mobs[i]);
            destruct(mob);
            continue;
        }

        // 更新mob環境
        mobs[i] = file_name(environment(mob));
    }


      // MOB 小於99隻時則增加
    i = sizeof(mobs);
    if( i < 99 ) {
        mob_dir = get_dir(GHOST_WAR_MOB_DIR);
        i = 99-i;
        if( i > 20 ) i = 20;
        while( i-- ) {
            j = random(sizeof(mob_dir));
            if( file_size(GHOST_WAR_MOB_DIR + mob_dir[j] ) == -1 ) continue; // 沒這檔
            if( file_size(GHOST_WAR_MOB_DIR + mob_dir[j] ) == -2 ) continue; // 是目錄
            mob = new( GHOST_WAR_MOB_DIR + mob_dir[j] );
            if( !objectp(mob) ) continue;
            room = load_object(GAMES["群魔亂舞"]["MOB_PLACE"][random(sizeof(GAMES["群魔亂舞"]["MOB_PLACE"]))]);
            if( !objectp(room) ) continue;
            if( !mob->move(room) ) continue;
            if( sscanf(get_object(mob),"%s (%s)", str, name) == 2)
                big_ghost_mob[str] = file_name(environment(mob));
        }
    }

    this_object()->save();
    return;
}

string get_object(object who) { return sprintf("%O", who); }

int do_dest_all_ghost()
{
    int i;
    string *mobs, msg;
    object mob;
    if( !mapp(GAMES) || undefinedp(GAMES["群魔亂舞"]) ) return 0;
    if( undefinedp(GAMES["群魔亂舞"]["TUNE"]) || !GAMES["群魔亂舞"]["TUNE"] ) return 0;

    mobs = keys(big_ghost_mob);

    for(i=0;i<sizeof(mobs);i++) {
        // mob 消失
        if( !objectp(mob = find_object(mobs[i])) ) {
            map_delete(big_ghost_mob, mobs[i]);
            continue;
        }

        // mob 沒環境
        if( !environment(mob) ) {
            map_delete(big_ghost_mob, mobs[i]);
            destruct(mob);
            continue;
        }

        // mob 刪除
        tell_room(environment(mob), "你聽見"+mob->query("name")+"身上發出「嗤∼嗤∼」之聲後，化成一陣青煙消失了。\n");
        map_delete(big_ghost_mob, mobs[i]);
        destruct(mob);
    }

    msg = "\n\t\t"HIW"【"HIG"天數異象"HIW"】"NOR"風雲變色，豬羊變胖，天搖地動，群魔退之！！！\n\n";
    message("world:world1:vision", msg ,users());
    GAMES["群魔亂舞"]["TUNE"] = 0;
    this_object()->save();
    return 1;
}

int do_list_all_ghost()
{
    int i;
    string *mobs, msg;
    object mob;

    if( !mapp(GAMES) || undefinedp(GAMES["群魔亂舞"]) ) return 0;
    if( undefinedp(GAMES["群魔亂舞"]["TUNE"]) || !GAMES["群魔亂舞"]["TUNE"] ) return 0;

    msg = "========================= 群魔亂舞 =========================\n";
    mobs = keys(big_ghost_mob);
     msg += "\t- 目前共有"+sizeof(mobs)+"隻Ghost -\n============================================================\n";

    for(i=0;i<sizeof(mobs);i++) {
        // mob 消失
        if( !objectp(mob = find_object(mobs[i])) ) {
            map_delete(big_ghost_mob, mobs[i]);
            continue;
        }

        // mob 沒環境
        if( !environment(mob) ) {
            map_delete(big_ghost_mob, mobs[i]);
            destruct(mob);
            continue;
        }

        // 更新mob環境
        mobs[i] = file_name(environment(mob));
        msg+= sprintf("編號：%3d %26s -> %s\n",
              i,mob->query("name") + "(" + mob->query("id") + ")",
              environment(mob)->query("short") + mobs[i]
        );

    }

    msg+= "============================================================\n";

    this_player()->start_more(msg);
    this_object()->save();
    return 1;
}

// 切換活動的開始與停止 
int tune_game(string game)
{
    if( !mapp(GAMES) || undefinedp(GAMES[game]) ) return 0;
    if( undefinedp(GAMES[game]["TUNE"]) ) GAMES[game]["TUNE"] = 0;
    if( GAMES[game]["TUNE"] == 0 ) GAMES[game]["TUNE"] = 1;
    else GAMES[game]["TUNE"] = 0;
    this_object()->save();
    return 1;
}

//  query活動是否在執行 
int query_tune_game(string game)
{
    if( !mapp(GAMES) || undefinedp(GAMES[game]) ) return 0;
    if( undefinedp(GAMES[game]["TUNE"]) ) return 0;
    return GAMES[game]["TUNE"];
}


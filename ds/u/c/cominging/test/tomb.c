//
// 根據所接收到的天氣訊息, 來改變房間的敘述
//
//                                              Created by Caesar

#include <mudlib.h>

inherit MONSTER;

#define ROOM_DIR "/u/c/caesar/home/"                    // 放房間的目錄

string status;
string query_weather_status() { return status; }        // 讓新載入的房間知
                                                        // 道現在是白天或晚上

int clean_up() { return 0; }                            // 讓他不被清掉

// 根據天氣, 來判斷白天或晚上, 可能會有點問題, 不過應該沒錯吧
void init_weather_status()
{
        switch( "/adm/daemons/weather_d"->query_current_day_phase() )
        {
                case "太陽的光芒開始出現在東方的地平線上。\n" :
                case "太陽剛剛出現在東方的地平線上﹐現在是清晨\n" :
                case "太陽從東方的地平線上昇起了。\n" :
                case "太陽高高掛在東方的天空中\n" :
                case "太陽已經昇到天空的正中央。\n" :
                case "太陽從你的正上方照耀著大地\n" :
                case "太陽開始向西移動。\n" :
                case "太陽高高掛在西邊的天空中\n" :
                case "太陽開始沒入西方的地平線。\n" :
                case "夕陽的餘輝照耀著西方的天邊\n" :
                case "最後一線夕陽的光芒也消失在地平線上。\n" :
                case "西邊的天空仍殘留著昏暗的夕陽餘輝\n" :
                        status = "白天";        
                        break;
                default :
                        status = "晚上";
                        break;
        }
}

void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "Weather Controled Daemon", "被天氣控制系統" );
        set_short( "被天氣控制系統" );
        set_long( "被天氣控制系統\n" );
        set_living_name( "Controled" );
        add( "id", ({ "controled", "daemon" }) );
        set( "gender", "neuter" );
        set( "unit", "台" );

        // 加入接收天氣變化的行列
        "/adm/daemons/weather_d"->request_weather_notices(this_object());
        
        // 取的現在的狀況, 是白天或晚上
        init_weather_status();
}

// 更改已載入房間的敘述
void change_room_long()
{
        object room;
        string *rooms, room_file;
        int    i;

        rooms = get_dir( ROOM_DIR );
        i = sizeof(rooms);

        while(i--)
        {
                room_file = ROOM_DIR + rooms[i];

                if( file_size( room_file ) == -2 )      // 目錄
                        continue;
                if( !room = find_object( room_file ) )  // 尚未載入的, 就不管他
                        continue;
                room->change_long(status);
        }
}

// 改寫 relay_message 讓他對天氣的變化有動作                
void relay_message(string cla, string msg)
{
        switch(msg)
        {
                case "太陽的光芒開始出現在東方的地平線上。\n" :
                        status = "白天";
                        change_room_long();
                        return;

                case "天空完全暗下來﹐夜晚降臨了。\n" :
                        status = "晚上";
                        change_room_long();
                        return;

                default :
                        return;
        }
}

inherit ROOM;
void create()
{
 set("short","青木堂");

 set("long",@LONG
青木堂是教中負責調查情報、防具武器強度、物品、探勘新區域
、解迷等事務。他們深入這個世界不為人知的地方，搜集各種可
靠的情報，破解各種迷題，為教中帶來許多福利。四周人來人往
，大家忙的不意樂乎，地上堆滿了資料，身旁的人正在測試防具
和思考如何解迷，面前的石碑刻滿了解迷的方法。
LONG
    );
 set("exits",([ "south": __DIR__"darkfire",
    ]));
        set("no_kill",1);
        set("light",1);
 setup();
        set("stroom",1);
}
//這裡該有個board
//have 明教聖語錄
//這是一個用來發問的留言板，當你有各種問題時請post，大家會
//幫你解決。

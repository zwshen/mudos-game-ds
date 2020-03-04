#include <room.h>
inherit ROOM;
void create()
{
 set("short","上將軍賓室");
 set("long",@LONG
你一進來, 就發現數名官兵正盯著你看, 讓你覺得渾身不自在,
仔細瞧了瞧四周, 發現擺設十分毫華, 而且許多官用品都在裡面, 
這邊站了大概四五名的護衛, 中間為首的體形較高大, 身上配件也
較精良, 龍眉鳳眼, 一看就知道是聖宗帝身邊第一號大將 ------
「司寇宏武」, 是有名的武狀元, 想不到大會散了, 他還留在向雲
堂之中, 或許你應該趕緊說聲抱歉溜出去才是.
LONG
    );
 set("exits",([ "north":__DIR__"inroom15",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

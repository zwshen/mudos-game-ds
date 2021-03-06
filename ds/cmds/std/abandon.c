// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg || arg=="" ) return notify_fail("你要放棄哪一項技能﹖\n");

	if( !me->delete_skill(arg) )
		return notify_fail("你並沒有學過這項技能。\n");
	if( arg == "combat" ) return notify_fail("這個技能無法忘記。\n");
	write("你決定放棄繼續學習" + to_chinese(arg) + "。\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式﹕abandon <技能名稱>

放棄一項你所學的技能，注意這裡所說的「放棄」是指將這項技能從你人物的資料中
刪除，如果你已後還要練，必須從 0 開始重練，請務必考慮清楚。

這個指令使用的場合通常是用來刪除一些「不小心」練出來的技能。
TEXT
	);
	return 1;
}

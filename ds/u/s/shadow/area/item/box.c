inherit BOX;

void create()
{
	set_name("紅木寶箱", ({ "treasure box", "box" }));
	set("long", @LONG
    一個暗紅色的寶箱，似乎有著相當久遠的年代，紮實的紅木用鐵
條緊箍著，上頭的鎖頭已經略為生鏽，但是堅固的設計仍然讓你無計
可施，看來若無法尋得寶箱的鑰匙，恐怕永遠也不知道這寶箱內究竟
藏著何種寶物。

LONG
	);
	
	set("value", 1);
	set("unit", "個");
	set("no_get", 1);
	
	/* 設定最大容量 */
	set_max_encumbrance(999999); 
	set_max_capacity(10);
		
	/* 設定可開的鑰匙的目錄+檔名 */
	set_keys(({__DIR__"key"})); 
		
	setup();
	
	/**
	 * set_cover(int)
	 * 2: 沒蓋子
	 * 3: 蓋子是打開
	 * 4: 蓋子被關上
	 * 5: 蓋子被破壞
	 */
	set_cover(4);

	/** 
	 * set_lock(int)
	 * 6: 沒鎖
	 * 7: 鎖是開的
	 * 8: 鎖是上鎖的
	 * 9: 鎖被破壞
	 */	
	set_lock(8);
}

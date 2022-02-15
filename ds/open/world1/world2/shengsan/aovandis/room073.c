// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���߹Ϯ��]"NOR);
	set("long", @LONG
�Ϯ��]�i���O���Ѫ��_�w�A�o�y���߹Ϯ��]�w�g���n�X�d�~�����v�F
�A���N�����������g���L�W�Ҥ��@���׾�س]�A�̭����îѥi���O�۷�
�״I�C�M�n���b�����ҡA�j�⧻�����ؿv�[�W�{�N�ƪ��]�ơA�o�y�Ϯ��]
�w�g�������Z�}�����a�Ф��@�F�C��W���ӧi�ܵP(sign)�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room019",
	    "up"   : __DIR__"room121",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/lib_mem0.c" : 1,
	]));

	set("item_desc", (["sign":@NOTE

�G�i�P�W�g��:

	�Цۦ��ӤW�����ɪ��ѥ���o�̹��A�ȤH����z�ɾ\����A
	�p�G�p�۱a�X�]�~�N�|����k�ߨ���C

		borrow    �ɮ�
		return    �ٮ�

NOTE
        ]) );
	set("no_clean_up", 0);
	set("light", 1);
	set("no_recall",1);
	set("valid_startroom",1);

	setup();
//	replace_program(ROOM);
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i,j,bookno,bookdate,coun;
	string *item,*ids,markid;
        if( dir=="north" )
	{
		ob = all_inventory(me);
		ob = sort_array(ob, "sort_item", this_object());
		item = me->query("aovandis/library");
		for(i=0;i<sizeof(ob);i++)
		{
			coun = 0;
			if(ob[i]->is_book())
			{
				for(j=0;j<sizeof(item);j++)
				{
					if(sscanf(item[j],"book%d_%d",bookno,bookdate)!=2)
						continue;
					if(ob[i]->query("id") == "book"+(string)bookno)
					{
						coun = 1;
						if(markid == ob[i]->query("id"))
							coun++;
						else
							markid = ob[i]->query("id");
					}
				}
				if(coun>=2)
					return notify_fail("�Ф��n�a���⥻�H�W���y"+ob[i]->query("name")+"�z�C\n");
				else if(coun<=0)
					return notify_fail("�y"+ob[i]->query("name")+"�z�O�Ϯ��]���ϮѡA�п�n�ɮѤ���A�����}�C\n");
			}
			else if(ob[i]->is_magzine() && !ob[i]->is_copy())
				return notify_fail("���Ϯ��]�ä��~�ɡu"+ob[i]->query("name")+"�v(���x)��C\n");
		}
	}
        return ::valid_leave(me, dir);
}

// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�\\�U�A�ȥx"NOR);
	set("long", @LONG
��������^�R���䤤�A�n���H�K�ߡC���ɪ���^�ϧA���جy�s�Ѫ�
�����C��W���F�@�T���e(picture)�A�Z�j�i���C�A�ȥx�W�����¦⪺��
�ت�(note)�C�p�G�ݭn�i�H�ЪA�ȤH�����A�A�ȡC
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room108",
	    "south": __DIR__"room109",
	    "west" : __DIR__"room080",
            ]));
 set("item_desc",([
        "picture":@PICTURE

   ��
   �� .           ���          .  ��. ��       ��     .  
  �z�w�w�{  .    �   .  ��            ..         ��    
  �x�l�l�x  ��             �z�w�w�w�{ ...
  �x    �x     ��    ��    �x �o �o�x          ��   ��
  �x�l�l�x                 �x      �x
  �x    �x             �z�w�t �o �o�x     �q      ��      
  �x�l�l�x        ��   �x�d�x      �x     �x    ��        
  �x    �u�w�w�w�{     �x  �x �o �o�x    ���@            
  �x�l�l�x      �x     �x�d�x      �x   �x  �x
  �x    �x�p �p �x     �x  �x �o �o�x �z�}  �|�{
  �x�l�l�x      �x     �x�d�x      �x �x��  ���x          
  �x    �x�p �p �x     �x  �x �o �o�u�w       �|�w�{       
  �x�l�l�x      �x     �x  �x      �x ���~�w�� �� �x
  �x    �x�p �p�w�w�w�w�w�w �w�{ �o�x   �x  �x    �x     
  �x�l�l�x    �x �� �� �� ��  �x   �x ���x  �x �� �x     
  �x    �x    �x              �x �o�x   �x  �x    �x          
  �x    �x    �x �� �� �� ��  �x   �x   �x  �x    �x      

PICTURE
,
        "note":@NOTE

�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{
�x �� ��                ����  �\�I                      �x
�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}
      30 .............. ����  �F��(Salad)               
     700 .............. ����  ����(Beefsteak)           

    
NOTE
,
         ]));
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}


; --------------------------------------------------------------------------- 
;  Hyper Operating System V4  サンプルプログラム                              
;    割り込みベクターテーブル                                                 
;                                                                             
;                                   Copyright (C) 1998-2002 by Project HOS    
;                                   http://sourceforge.jp/projects/hos/       
; --------------------------------------------------------------------------- 

		.h8300h

; -----------------------------------------------
;          割り込みベクタテーブル
; -----------------------------------------------
		.section	.vectors

		.long	_startup
		.long	_hos_vector001
		.long	_hos_vector002
		.long	_hos_vector003
		.long	_hos_vector004
		.long	_hos_vector005
		.long	_hos_vector006
		.long	_hos_vector007
		.long	_hos_vector008
		.long	_hos_vector009
		.long	_hos_vector010
		.long	_hos_vector011
		.long	_hos_vector012
		.long	_hos_vector013
		.long	_hos_vector014
		.long	_hos_vector015
		.long	_hos_vector016
		.long	_hos_vector017
		.long	_hos_vector018
		.long	_hos_vector019
		.long	_hos_vector020
		.long	_hos_vector021
		.long	_hos_vector022
		.long	_hos_vector023
		.long	_hos_vector024
		.long	_hos_vector025
		.long	_hos_vector026
		.long	_hos_vector027
		.long	_hos_vector028
		.long	_hos_vector029
		.long	_hos_vector030
		.long	_hos_vector031
		.long	_hos_vector032
		.long	_hos_vector033
		.long	_hos_vector034
		.long	_hos_vector035
		.long	_hos_vector036
		.long	_hos_vector037
		.long	_hos_vector038
		.long	_hos_vector039
		.long	_hos_vector040
		.long	_hos_vector041
		.long	_hos_vector042
		.long	_hos_vector043
		.long	_hos_vector044
		.long	_hos_vector045
		.long	_hos_vector046
		.long	_hos_vector047
		.long	_hos_vector048
		.long	_hos_vector049
		.long	_hos_vector050
		.long	_hos_vector051
		.long	_hos_vector052
		.long	_hos_vector053
		.long	_hos_vector054
		.long	_hos_vector055
		.long	_hos_vector056
		.long	_hos_vector057
		.long	_hos_vector058
		.long	_hos_vector059
		.long	_hos_vector060
		.long	_hos_vector061
		.long	_hos_vector062
		.long	_hos_vector063



		.end



; --------------------------------------------------------------------------- 
;  Copyright (C) 1998-2002 by Project HOS                                     
; --------------------------------------------------------------------------- 

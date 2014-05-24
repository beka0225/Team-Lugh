#include <Windows.h>
#include <mmsystem.h>

#include "Direct3D.h"
#include "Core.h"

#include "DirectInput.h"
#include "DirectSound.h"

#include "SceneHeader.h"
#include "SceneManager.h"
//#include "Setting.h"


CStartScene::CStartScene(void)
{
	BG1 = new CBackGround;
	BG2 = new CBackGround;
	BG1->Init( L"Image\\BackGround\\BackGround_Far.png" , 0 , 0 , 0.9 );
	BG2->Init( L"Image\\BackGround\\BackGround_Close.png", 0 ,0, 0);

	/*
	m_BGTex = NULL;
	m_MenuTex = NULL;
	m_SelectedTex = NULL;
	m_CreateTexture = NULL;*/
}


CStartScene::~CStartScene(void)
{

}

bool CStartScene::Initialize()
{
	temp.Init( "Data\\game_option.ini" ) ;
	temp.SetSection( "Option" );
	temp.SetKey("MouseSense");
	temp.Write( 56 );

	cout<<temp.Read()<<endl;
	/*
	DirectSound()->Play_Sound(0, true);
	DirectSound()->Set_Volume(50L);

	m_fStartTime = static_cast<float>(timeGetTime()) * 0.001f;
	
	

	if ( m_BGTex->AddUITexture( m_CreateTexture->GetTexture(0),	0.0f, 0.0f, 0.9f ) == false ) return false;
	if ( m_BGTex->AddUITexture( m_CreateTexture->GetTexture(1),		360.0f, 300.0f, 0.5f ) == false ) return false;

	if ( m_MenuTex->AddUITexture( m_CreateTexture->GetTexture(2),	1072.0f, 506.0f, 0.5f ) == false ) return false;
	if ( m_MenuTex->AddUITexture( m_CreateTexture->GetTexture(3),	1072.0f, 556.0f, 0.5f ) == false ) return false;
	if ( m_MenuTex->AddUITexture( m_CreateTexture->GetTexture(4),		1072.0f, 606.0f, 0.5f ) == false ) return false;
	if ( m_MenuTex->AddUITexture( m_CreateTexture->GetTexture(5),		1072.0f, 656.0f, 0.5f ) == false ) return false;

	if ( m_SelectedTex->Initialize( m_CreateTexture->GetTexture(6), 1052.0f, 490.0f, 0.6f ) == false ) return false;

	TransitionManager()->TransitionChange( TransitionType::Fade );
	TransitionManager()->SetTransition(TransitionOption::In);
	m_CurrentCursor = 1;
	m_Click = 0;
		
	m_BGTex->SetisUI(0 , true);
	*/

	return true;
}

void CStartScene::UnInitialize()
{
	BG1->UnInit();
	BG2->UnInit();

/*	if ( m_BGTex != NULL )
	{
		m_BGTex->ReleaseTexture();
		delete m_BGTex;
		m_BGTex = NULL;
	}

	if ( m_MenuTex != NULL )
	{
		m_MenuTex->ReleaseTexture();
		delete m_MenuTex;
		m_MenuTex = NULL;
	}

	if ( m_SelectedTex != NULL )
	{
		m_SelectedTex->RemoveImage();
		delete m_SelectedTex;
		m_SelectedTex = NULL;
	}*/
}

bool CStartScene::TextureInitialize()
{
	/*
	m_CreateTexture = new CCreateTexture;
	// m_BGTex	BG
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\BackGroundAincrad.png" ) ) == false ) return false;
	if ( m_BGTex != NULL )
	{
		m_BGTex->GetRepsitory(0)->ReTextureInitialize( m_CreateTexture->GetTexture(0) );
	}

	// m_BGTex	Logo
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\Logo.png" ) ) == false ) return false;
	if ( m_BGTex != NULL )
	{
		m_BGTex->GetRepsitory(1)->ReTextureInitialize( m_CreateTexture->GetTexture(1) );
	}

	// m_MenuTex	New
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\Menu\\Link Start.png" ) ) == false ) return false;
	if ( m_MenuTex != NULL )
	{
		m_MenuTex->GetRepsitory(0)->ReTextureInitialize( m_CreateTexture->GetTexture(2) );
	}

	// m_MenuTex	Setting
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\Menu\\Setting.png" ) ) == false ) return false;
	if ( m_MenuTex != NULL )
	{
		m_MenuTex->GetRepsitory(3)->ReTextureInitialize( m_CreateTexture->GetTexture(3) );
	}

	// m_MenuTex	Credit
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\Menu\\Credit.png" ) ) == false ) return false;
	if ( m_MenuTex != NULL )
	{
		m_MenuTex->GetRepsitory(4)->ReTextureInitialize( m_CreateTexture->GetTexture(4) );
	}

	// m_MenuTex	Exit
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\Menu\\Exit.png" ) ) == false ) return false;
	if ( m_MenuTex != NULL )
	{
		m_MenuTex->GetRepsitory(5)->ReTextureInitialize( m_CreateTexture->GetTexture(5) );
	}

	// m_SelectedTex	
	if ( ( m_CreateTexture->AddTexture( L"Image\\MainMenu\\Menu\\Selected.png" ) ) == false ) return false;
	if ( m_SelectedTex != NULL )
	{
		m_SelectedTex->ReTextureInitialize( m_CreateTexture->GetTexture(6) );
	}
	*/
	return true;
}

void CStartScene::TextureUnInitialize()
{
	/*
	m_CreateTexture->ReleaseTexture();
	delete m_CreateTexture;
	m_CreateTexture = NULL;*/
}

void CStartScene::PrepareInput()
{
	if( DirectInput()->KeyPress(DIK_RIGHT) )
	{
		Camera()->Move( MOVE_VAL );
	}
		if( DirectInput()->KeyPress(DIK_LEFT) )
	{
		Camera()->Move( -MOVE_VAL );
	}

		if( DirectInput()->KeyPress(DIK_UP) )
	{
		Camera()->Move( 0,-MOVE_VAL );
	}

		if( DirectInput()->KeyPress(DIK_DOWN) )
	{
		Camera()->Move( 0,MOVE_VAL );
	}

	if ( DirectInput()->KeyDown(DIK_ESCAPE ) )
	{
		PostQuitMessage(0);
	}
	//���⼭ �����Ұ��� �޴����� ������ ���� ������(1), �ǾƷ���  ������(6) �̴�.
	/*
	m_fElapsedTime = static_cast<float>(timeGetTime()) * 0.001f;

	// ����Ű
	if ( DirectInput()->KeyPress( DIK_UP ) == true )
	{
		if( m_fElapsedTime -m_fStartTime >= 0.25f )
		{
			DirectSound()->Play_Sound(1);
			// �׸��� Ŀ���� �ǾƷ� ������ �� �Ʒ��ΰ���
			if ( m_CurrentCursor <= 1 )
			{ 
				m_SelectedTex->SmoothMove( 1052.0f, 640.0f, 0.18f );
				m_CurrentCursor = 4; // �ǾƷ���
			}
			else
			{
				m_SelectedTex->SmoothMove( 1052.0f, 440.0f+(--m_CurrentCursor * 50.0f), 0.22f );
			}
			m_fStartTime = m_fElapsedTime ;
		}
	}
	// ���� ��Ȳ���� �ݴ�� �Ʒ������� �̵�.
	else if ( DirectInput()->KeyPress( DIK_DOWN ) == true )
	{ 
		if( m_fElapsedTime -m_fStartTime >= 0.25f )
		{
			DirectSound()->Play_Sound(1);
			if ( m_CurrentCursor >= 4 )
			{
				m_SelectedTex->SmoothMove( 1052.0f, 490.0f, 0.18f );
				m_CurrentCursor = 1;
			}
			else
			{
				m_SelectedTex->SmoothMove( 1052.0f, 490.0f+(m_CurrentCursor++ * 50.0f), 0.22f );
			}
			m_fStartTime = m_fElapsedTime ;
		}
	}

	// �׸��� �����ϸ�
	if ( DirectInput()->KeyDown( DIK_Z ) == true || DirectInput()->KeyDown(DIK_RETURN) == true )
	{ 
		DirectSound()->Play_Sound(2);
		TransitionManager()->SetTransition(TransitionOption::Out); // ����ȭ������ �Ѿ�� ���̵� ȿ��
		m_Click = true; // Ŭ���̵�
	}

	// ESCŰ�� ������ (�޴� ���ð� �������) ���� ȭ������
	if ( DirectInput()->KeyDown( DIK_ESCAPE ) == true )
	{
		m_Click = true;
		m_CurrentCursor = 6;
		TransitionManager()->SetTransition(TransitionOption::Out);
		SceneManager()->ChangeScene( new CQuitScene() );
	}*/
}

void CStartScene::Process()
{
	BG1->Process();
	BG2->Process();
	return;
	/*
	m_SelectedTex->Process();
	m_BGTex->Process();
	m_MenuTex->Process();

	if ( m_Click == true )// �׸��� �����Ұ��
	{ 
		switch ( m_CurrentCursor )
		{

		case 1:// ���ӽ����� ���̵����� ������
			{ 
				SceneManager()->ChangeScene( new CStartTown_0() );
				break;
			}

		case 2:// ����
			{ 
				SceneManager()->ChangeScene( new CSetting() );
				TransitionManager()->SetTransition(TransitionOption::In);
				break;
			}

		case 3:// ũ����
			{ 
				SceneManager()->ChangeScene( new CCreditScene() );
				TransitionManager()->SetTransition(TransitionOption::In);
				break;
			}

		case 4:// ���� �Ұ����� ���� ������
			{ 
				SceneManager()->ChangeScene( new CQuitScene() );
				break;
			}
		}
	}*/
}

void CStartScene::Render()
{
	BG1->Render();
	BG2->Render();
	return;
	/*
	m_BGTex->Render();
	m_MenuTex->	Render();
	m_SelectedTex->Render();*/
}
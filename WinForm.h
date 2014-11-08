#pragma once

#include "MyCV.h"
#include "Gabor.h"
#include <msclr/marshal_cppstd.h>
#include "include\opencv2\core\core.hpp"
#include "include\opencv2\highgui\highgui.hpp"

MyCV w_opencv;

namespace CWinFormOpenCV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;

	/// <summary>
	/// WinForm ���K�n
	/// </summary>
	public ref class WinForm : public System::Windows::Forms::Form
	{
	public:
		WinForm(void)
		{
			InitializeComponent();
			//
			//TODO: �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~WinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loadImageButton;
	private: System::Windows::Forms::PictureBox^  originPictureBox;
	protected: 

	private: System::Windows::Forms::OpenFileDialog^  fileChooser;
	private: System::Windows::Forms::Button^  histButton;
	private: System::Windows::Forms::Button^  SIFTButton;
	private: System::Windows::Forms::Button^  huButton;
	private: System::Windows::Forms::TextBox^  huTextBox;
	private: System::Windows::Forms::Button^  gaborButton;




	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边
		/// �ק�o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->loadImageButton = (gcnew System::Windows::Forms::Button());
			this->originPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->fileChooser = (gcnew System::Windows::Forms::OpenFileDialog());
			this->histButton = (gcnew System::Windows::Forms::Button());
			this->SIFTButton = (gcnew System::Windows::Forms::Button());
			this->huButton = (gcnew System::Windows::Forms::Button());
			this->huTextBox = (gcnew System::Windows::Forms::TextBox());
			this->gaborButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->originPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// loadImageButton
			// 
			this->loadImageButton->Location = System::Drawing::Point(90, 51);
			this->loadImageButton->Name = L"loadImageButton";
			this->loadImageButton->Size = System::Drawing::Size(75, 23);
			this->loadImageButton->TabIndex = 0;
			this->loadImageButton->Text = L"Load Image";
			this->loadImageButton->UseVisualStyleBackColor = true;
			this->loadImageButton->Click += gcnew System::EventHandler(this, &WinForm::loadImageButton_Click);
			// 
			// originPictureBox
			// 
			this->originPictureBox->Location = System::Drawing::Point(291, 12);
			this->originPictureBox->Name = L"originPictureBox";
			this->originPictureBox->Size = System::Drawing::Size(411, 418);
			this->originPictureBox->TabIndex = 1;
			this->originPictureBox->TabStop = false;
			// 
			// fileChooser
			// 
			this->fileChooser->FileName = L"fileChooser";
			this->fileChooser->Filter = L"�I�}���ɮ� (*.bmp;*.dib)|*.bmp|JPEG (*.jpg;*.jpeg;*.jpe;*.jfif)|*.jpg|GIF (*.gif)|*.gi" 
				L"f|TIFF (*.tiff;*.tif)|*.tiff|PNG (*.png)|*.png|ICO (*.ico)|*.ico|�Ҧ��ɮ� (*.*)|*.*";
			this->fileChooser->FilterIndex = 7;
			this->fileChooser->Multiselect = true;
			this->fileChooser->Title = L"����v��";
			// 
			// histButton
			// 
			this->histButton->Location = System::Drawing::Point(90, 104);
			this->histButton->Name = L"histButton";
			this->histButton->Size = System::Drawing::Size(75, 23);
			this->histButton->TabIndex = 2;
			this->histButton->Text = L"Histogram";
			this->histButton->UseVisualStyleBackColor = true;
			this->histButton->Click += gcnew System::EventHandler(this, &WinForm::histButton_Click);
			// 
			// SIFTButton
			// 
			this->SIFTButton->Location = System::Drawing::Point(90, 154);
			this->SIFTButton->Name = L"SIFTButton";
			this->SIFTButton->Size = System::Drawing::Size(75, 23);
			this->SIFTButton->TabIndex = 3;
			this->SIFTButton->Text = L"SIFT";
			this->SIFTButton->UseVisualStyleBackColor = true;
			this->SIFTButton->Click += gcnew System::EventHandler(this, &WinForm::SIFTButton_Click);
			// 
			// huButton
			// 
			this->huButton->Location = System::Drawing::Point(90, 205);
			this->huButton->Name = L"huButton";
			this->huButton->Size = System::Drawing::Size(75, 23);
			this->huButton->TabIndex = 4;
			this->huButton->Text = L"Hu Moments";
			this->huButton->UseVisualStyleBackColor = true;
			this->huButton->Click += gcnew System::EventHandler(this, &WinForm::huButton_Click);
			// 
			// huTextBox
			// 
			this->huTextBox->Location = System::Drawing::Point(12, 234);
			this->huTextBox->Name = L"huTextBox";
			this->huTextBox->Size = System::Drawing::Size(273, 22);
			this->huTextBox->TabIndex = 5;
			this->huTextBox->Text = L"0";
			// 
			// gaborButton
			// 
			this->gaborButton->Location = System::Drawing::Point(90, 262);
			this->gaborButton->Name = L"gaborButton";
			this->gaborButton->Size = System::Drawing::Size(75, 23);
			this->gaborButton->TabIndex = 6;
			this->gaborButton->Text = L"Gabor";
			this->gaborButton->UseVisualStyleBackColor = true;
			this->gaborButton->Click += gcnew System::EventHandler(this, &WinForm::gaborButton_Click);
			// 
			// WinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 442);
			this->Controls->Add(this->gaborButton);
			this->Controls->Add(this->huTextBox);
			this->Controls->Add(this->huButton);
			this->Controls->Add(this->SIFTButton);
			this->Controls->Add(this->histButton);
			this->Controls->Add(this->originPictureBox);
			this->Controls->Add(this->loadImageButton);
			this->Name = L"WinForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->originPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadImageButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (fileChooser->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

					 // read an image & resize it to fit the picture box
					 w_opencv.readImage(msclr::interop::marshal_as<std::string>(fileChooser->FileName));
					 Bitmap^ tempImage = w_opencv.getBitmap();
					 Bitmap^ originImage = gcnew Bitmap(tempImage, originPictureBox->Size);
					 originPictureBox->Image = originImage;
				 }
			 }
	private: System::Void histButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 int histSize = 16;
				 float range[] = { 0, 256 } ;
				 const float* histRange = { range };

				 w_opencv.calHistogram(histSize, histRange);


			 }
	private: System::Void SIFTButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 w_opencv.detectSIFT();
			 }
	private: System::Void huButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 w_opencv.HuMoment();

				 std::vector<double> huVector = w_opencv.getHuVector();
				 huTextBox->Text = "";
				 for(int i=0; i<huVector.size(); i++)
				 {
					 huTextBox->Text += L"Hu Moment hu" + (i+1) + ": " + ToString()->Format("{0:0.000000000000}",huVector[i]) + "\r\n";
				 }
			 }
	private: System::Void gaborButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 
			 }
};
}
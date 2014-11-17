#pragma once

#include "MyCV.h"
#include "fourier.h"
#include "MySVM.h"
#include "include\dirent.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include "include\opencv2\core\core.hpp"
#include "include\opencv2\highgui\highgui.hpp"

extern MyCV w_opencv;
extern fourier w_fourier;
extern MySVM w_svm;

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

	private: System::Windows::Forms::PictureBox^  originPictureBox;
	private: System::Windows::Forms::OpenFileDialog^  modelChooser;
	private: System::Windows::Forms::TextBox^  fileTextBox;
	private: System::Windows::Forms::TextBox^  modelTextBox;
	protected: 


	private: System::Windows::Forms::Button^  truthButton;
	private: System::Windows::Forms::Button^  falseButton;
	private: System::Windows::Forms::Button^  trainButton;
	private: System::Windows::Forms::Button^  testButton;

	private: System::Windows::Forms::Button^  modelButton;
	private: System::Windows::Forms::Button^  button1;
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
			this->originPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->modelChooser = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileTextBox = (gcnew System::Windows::Forms::TextBox());
			this->modelTextBox = (gcnew System::Windows::Forms::TextBox());
			this->truthButton = (gcnew System::Windows::Forms::Button());
			this->falseButton = (gcnew System::Windows::Forms::Button());
			this->trainButton = (gcnew System::Windows::Forms::Button());
			this->testButton = (gcnew System::Windows::Forms::Button());
			this->modelButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->originPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// originPictureBox
			// 
			this->originPictureBox->Location = System::Drawing::Point(291, 65);
			this->originPictureBox->Name = L"originPictureBox";
			this->originPictureBox->Size = System::Drawing::Size(640, 360);
			this->originPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->originPictureBox->TabIndex = 1;
			this->originPictureBox->TabStop = false;
			// 
			// modelChooser
			// 
			this->modelChooser->FileName = L"svm_data_auto.xml";
			this->modelChooser->Filter = L"XML�ɮ� (*.xml)|*.xml|�Ҧ��ɮ� (*.*)|*.*";
			this->modelChooser->FilterIndex = 0;
			this->modelChooser->Title = L"���������";
			// 
			// fileTextBox
			// 
			this->fileTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->fileTextBox->Location = System::Drawing::Point(12, 358);
			this->fileTextBox->Multiline = true;
			this->fileTextBox->Name = L"fileTextBox";
			this->fileTextBox->Size = System::Drawing::Size(273, 39);
			this->fileTextBox->TabIndex = 5;
			// 
			// modelTextBox
			// 
			this->modelTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->modelTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->modelTextBox->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->modelTextBox->Location = System::Drawing::Point(291, 13);
			this->modelTextBox->Multiline = true;
			this->modelTextBox->Name = L"modelTextBox";
			this->modelTextBox->Size = System::Drawing::Size(639, 50);
			this->modelTextBox->TabIndex = 14;
			// 
			// truthButton
			// 
			this->truthButton->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->truthButton->Location = System::Drawing::Point(41, 23);
			this->truthButton->Name = L"truthButton";
			this->truthButton->Size = System::Drawing::Size(213, 33);
			this->truthButton->TabIndex = 9;
			this->truthButton->Text = L"Ground Truth";
			this->truthButton->UseVisualStyleBackColor = true;
			this->truthButton->Click += gcnew System::EventHandler(this, &WinForm::truthButton_Click);
			// 
			// falseButton
			// 
			this->falseButton->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->falseButton->Location = System::Drawing::Point(41, 65);
			this->falseButton->Name = L"falseButton";
			this->falseButton->Size = System::Drawing::Size(213, 33);
			this->falseButton->TabIndex = 10;
			this->falseButton->Text = L"Ground False";
			this->falseButton->UseVisualStyleBackColor = true;
			this->falseButton->Click += gcnew System::EventHandler(this, &WinForm::falseButton_Click);
			// 
			// trainButton
			// 
			this->trainButton->Enabled = false;
			this->trainButton->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->trainButton->Location = System::Drawing::Point(41, 116);
			this->trainButton->Name = L"trainButton";
			this->trainButton->Size = System::Drawing::Size(213, 33);
			this->trainButton->TabIndex = 11;
			this->trainButton->Text = L"Train";
			this->trainButton->UseVisualStyleBackColor = true;
			this->trainButton->Click += gcnew System::EventHandler(this, &WinForm::trainButton_Click);
			// 
			// testButton
			// 
			this->testButton->Enabled = false;
			this->testButton->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->testButton->Location = System::Drawing::Point(41, 294);
			this->testButton->Name = L"testButton";
			this->testButton->Size = System::Drawing::Size(213, 33);
			this->testButton->TabIndex = 12;
			this->testButton->Text = L"Test";
			this->testButton->UseVisualStyleBackColor = true;
			this->testButton->Click += gcnew System::EventHandler(this, &WinForm::testButton_Click);
			// 
			// modelButton
			// 
			this->modelButton->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->modelButton->Location = System::Drawing::Point(41, 225);
			this->modelButton->Name = L"modelButton";
			this->modelButton->Size = System::Drawing::Size(213, 33);
			this->modelButton->TabIndex = 13;
			this->modelButton->Text = L"Choose Model";
			this->modelButton->UseVisualStyleBackColor = true;
			this->modelButton->Click += gcnew System::EventHandler(this, &WinForm::modelButton_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(41, 165);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 33);
			this->button1->TabIndex = 15;
			this->button1->Text = L"to .txt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WinForm::button1_Click);
			// 
			// WinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(942, 437);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->modelButton);
			this->Controls->Add(this->testButton);
			this->Controls->Add(this->trainButton);
			this->Controls->Add(this->falseButton);
			this->Controls->Add(this->truthButton);
			this->Controls->Add(this->fileTextBox);
			this->Controls->Add(this->modelTextBox);
			this->Controls->Add(this->originPictureBox);
			this->Name = L"WinForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->originPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: int getdir(std::string dir, vector<std::string> &files) {
				 DIR *dp;//�Х߸�Ƨ�����
				 struct dirent *dirp;
				 if((dp = opendir(dir.c_str())) == NULL){
					 cout << "Error(" << errno << ") opening " << dir << endl;
					 return errno;
				 }
				 while((dirp = readdir(dp)) != NULL)
				 {//�p�Gdirent���ЫD��
					 files.push_back(std::string(dirp->d_name));//�N��Ƨ��M�ɮצW��Jvector
				 }
				 closedir(dp);//������Ƨ�����
				 return 0;
			 }
	private: System::Void truthButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 FolderBrowserDialog^ folderBrowserDiaglog = gcnew FolderBrowserDialog();
				 if (folderBrowserDiaglog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
					 return;
				 }
				 std::string path = msclr::interop::marshal_as<std::string>(folderBrowserDiaglog->SelectedPath);

				 vector<std::string> filenames = vector<std::string>();
				 getdir(path,filenames);

				 vector<std::string> all_files = vector<std::string>();
				 std::string message;
				 for(unsigned int i = 0; i < filenames.size(); i++)
				 {
					 if (filenames[i] == "." || filenames[i] == "..")
						 continue;
					 message = path + "\\" + filenames[i];
					 all_files.push_back(message);
				 }
				 w_svm.setTXTName(filenames[3]);
				 
				 for (unsigned int i = 0; i < all_files.size(); ++i) {
					 w_opencv.readImage(all_files[i]);

					 /*int histSize = 16;
					 float range[] = { 0, 256 } ;
					 const float* histRange = { range };
					 w_opencv.calHistogram(histSize, histRange);*/

					 w_opencv.detectSIFT();

					 w_opencv.HuMoment();
					 std::vector<float> huVector = w_opencv.getHuVector();

					 w_fourier.image_process(w_opencv.getImage());

					 vector< vector<float> > features;

					 features.push_back(w_opencv.getHistVector());
					 features.push_back(w_opencv.getHuVector());
					 features.push_back(w_opencv.getSiftVector());
					 features.push_back(w_fourier.get_vector());

					 w_svm.concatenateGt(features);

					 features.clear();
					 w_opencv.clear();
					 w_fourier.clear_vector();

					 System::String^ string = gcnew System::String(all_files[i].c_str());
					 fileTextBox->Text = string;
					 fileTextBox->Refresh();
				 }

				 MessageBoxA(0, "�]���F!", "Ground Truth", MB_OK);
			 }
	private: System::Void falseButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 FolderBrowserDialog^ folderBrowserDiaglog = gcnew FolderBrowserDialog();
				 if (folderBrowserDiaglog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
					 return;
				 }
				 std::string path = msclr::interop::marshal_as<std::string>(folderBrowserDiaglog->SelectedPath);

				 vector<std::string> filenames = vector<std::string>();
				 getdir(path,filenames);

				 vector<std::string> all_files = vector<std::string>();
				 std::string message;
				 for(unsigned int i = 0; i < filenames.size(); i++)
				 {
					 if (filenames[i] == "." || filenames[i] == "..")
						 continue;
					 message = path + "\\" + filenames[i];
					 all_files.push_back(message);
				 }

				 for (unsigned int i = 0; i < all_files.size(); ++i) {
					 w_opencv.readImage(all_files[i]);

					 /*int histSize = 16;
					 float range[] = { 0, 256 } ;
					 const float* histRange = { range };
					 w_opencv.calHistogram(histSize, histRange);*/

					 w_opencv.detectSIFT();

					 w_opencv.HuMoment();
					 std::vector<float> huVector = w_opencv.getHuVector();

					 w_fourier.image_process(w_opencv.getImage());

					 vector< vector<float> > features;

					 features.push_back(w_opencv.getHistVector());
					 features.push_back(w_opencv.getHuVector());
					 features.push_back(w_opencv.getSiftVector());
					 features.push_back(w_fourier.get_vector());

					 w_svm.concatenateOther(features);

					 features.clear();
					 w_opencv.clear();
					 w_fourier.clear_vector();

					 System::String^ string = gcnew System::String(all_files[i].c_str());
					 fileTextBox->Text = string;
					 fileTextBox->Refresh();
				 }

				 MessageBoxA(0, "�]���F!", "Ground False", MB_OK);

				 trainButton->Enabled = true;
			 }
	private: System::Void trainButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 w_svm.trainSVM();
				 MessageBoxA(0, "�]���F!", "SVM", MB_OK);
			 }
	private: System::Void modelButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (modelChooser->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
					 return;
				 }
				 
				 std::string modelFile = msclr::interop::marshal_as<std::string>(modelChooser->FileName);

				 w_svm.setModel(modelFile);

				 modelTextBox->Text = gcnew System::String(modelFile.c_str());

				 testButton->Enabled = true;
			 }
	private: System::Void testButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 /* OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
				 openFileDialog1->InitialDirectory = "C:\\�ୱ";
				 openFileDialog1->Filter = "Image Files (*.jpg, *.bmp, *.gif, *.tga)|*.jpg; *.bmp; *.gif; *.tga ";
				 openFileDialog1->Title = "�}�ҹϤ���";

				 if (openFileDialog1->ShowDialog(this) == System::Windows::Forms::DialogResult::Cancel)   // �ϥΪ̨S�����ɮ�
				 return;

				 std::string file;	
				 file = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
				 //w_opencv.readImage(file);*/

				 FolderBrowserDialog^ folderBrowserDiaglog = gcnew FolderBrowserDialog();
				 folderBrowserDiaglog->ShowDialog();
				 std::string path = msclr::interop::marshal_as<std::string>(folderBrowserDiaglog->SelectedPath);

				 vector<std::string> filenames = vector<std::string>();
				 getdir(path,filenames);

				 vector<std::string> all_files = vector<std::string>();
				 std::string message;
				 for(unsigned int i = 0; i < filenames.size(); i++)
				 {
					 if (filenames[i] == "." || filenames[i] == "..")
						 continue;
					 message = path + "\\" + filenames[i];
					 all_files.push_back(message);
				 }

				 ofstream output("output.txt", ios::out);

				 for (unsigned int i = 0; i < all_files.size(); ++i) {
					 w_opencv.readImage(all_files[i]);

					 Bitmap^ testImage = w_opencv.getBitmap();
					 if (testImage->Width > originPictureBox->Width || testImage->Height > originPictureBox->Height) {
						 Bitmap^ resizeImage = gcnew Bitmap(testImage, originPictureBox->Size);
						 originPictureBox->Image = resizeImage;
					 }
					 else {
						 originPictureBox->Image = testImage;
					 }
					 originPictureBox->Refresh();

					 /*int histSize = 16;
					 float range[] = { 0, 256 } ;
					 const float* histRange = { range };
					 w_opencv.calHistogram(histSize, histRange);*/

					 w_opencv.detectSIFT();

					 w_opencv.HuMoment();
					 std::vector<float> huVector = w_opencv.getHuVector();

					 w_fourier.image_process(w_opencv.getImage());

					 vector< vector<float> > features;

					 features.push_back(w_opencv.getHistVector());
					 features.push_back(w_opencv.getHuVector());
					 features.push_back(w_opencv.getSiftVector());
					 features.push_back(w_fourier.get_vector());

					 w_svm.concatenateTest(features);

					 System::String^ string = gcnew System::String(all_files[i].c_str());
					 fileTextBox->Text = string;
					 fileTextBox->Refresh();

					 float res = w_svm.testSVM();
					 //MessageBoxA(0, std::to_string(res).c_str(), "SVM", MB_OK);

					 char result[128];
					 sprintf(result, "%s\t%f\r\n", all_files[i].c_str(), res);  
					 output << result;

					 features.clear();
					 w_opencv.clear();
					 w_fourier.clear_vector();
					 w_svm.clear_testVector();
				 }

				 output.close();
				 MessageBoxA(0, "�]���F!", "SVM", MB_OK);
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //set file name
			 w_svm.VectorToFile();
			 MessageBoxA(0, "�g���F!", "Ground Truth", MB_OK);
		 }
};
}
#pragma once
#pragma warning( disable : 4351 )	// �������q���Ŕz��̏������������ꍇ�ɏo��x��������

namespace Math
{
	typedef struct Vector2	  Vector2;
	typedef struct Vector3	  Vector3;
	typedef struct Vector4	  Vector4;
	typedef struct Quaternion Quaternion;
	typedef struct Matrix	  Matrix;

	extern const Math::Vector3 XAXIS;
	extern const Math::Vector3 YAXIS;
	extern const Math::Vector3 ZAXIS;

	//Normalize Functions
	extern void Normalize(Math::Vector2&	 target);
	extern void Normalize(Math::Vector3&	 target);
	extern void Normalize(Math::Vector4&	 target);
	extern void Normalize(Math::Quaternion& target);

	//Transform Functions
	/*extern void TransformByMatrix	 ( Math::Vector2& out, const Math::Vector2& in, const Math::Matrix&		matrix	   );
	extern void TransformByMatrix	 ( Math::Vector3& out, const Math::Vector3& in, const Math::Matrix&		matrix	   );
	extern void TransformByMatrix	 ( Math::Vector4& out, const Math::Vector4& in, const Math::Matrix&		matrix	   );
	extern void TransformByQuaternion( Math::Vector2& out, const Math::Vector2& in, const Math::Quaternion& quaternion );
	extern void TransformByQuaternion( Math::Vector3& out, const Math::Vector3& in, const Math::Quaternion& quaternion );
	extern void TransformByQuaternion( Math::Vector4& out, const Math::Vector4& in, const Math::Quaternion& quaternion );*/

	//Vector2 Functions
	extern void	GetVector2Rotation(Math::Vector2&		 out, const Math::Vector2& in, float					   radian);
	extern void	GetVector2TransformMatrix(Math::Vector2&		 out, const Math::Vector3& in, const Math::Matrix&  matrix);
	extern Math::Vector2 operator *		 (float					  left, const Math::Vector2& right);
	extern Math::Vector2 operator *		 (const Math::Vector2&   left, float		 			 right);

	//Vector3 Functions
	extern void	GetVector3Cross(Math::Vector3& out, const Math::Vector3& left, const Math::Vector3&	   right);
	extern void	GetVector3RotationX(Math::Vector3& out, const Math::Vector3& in, float	radian);
	extern void	GetVector3RotationY(Math::Vector3& out, const Math::Vector3& in, float radian);
	extern void	GetVector3RotationZ(Math::Vector3& out, const Math::Vector3& in, float radian);
	extern void	GetVector3RotationAxis(Math::Vector3& out, const Math::Vector3& in, const Math::Vector3&	   axis, float radian);
	extern void	GetVector3RotationQuaternion(Math::Vector3& out, const Math::Vector3& in, const Math::Quaternion& quat);
	extern void	GetVector3Slerp(Math::Vector3& out, const Math::Vector3& start, const Math::Vector3&    end, float t);
	extern void	GetVector3TransformMatrix(Math::Vector3& out, const Math::Vector3& in, const Math::Matrix& matrix);
	extern void	GetVector3TransformToScreen(Math::Vector3& out, const Math::Vector3& in, const Math::Matrix& matView, const Math::Matrix& matProj, const Math::Matrix& matViewport);
	extern void	GetVector3TransformToScreen(Math::Vector3& out, const Math::Vector3& in, const Math::Matrix& matWorld, const Math::Matrix& matView, const Math::Matrix& matProj, const Math::Matrix& matViewport);
	extern Math::Vector3 operator *		 (float					left, const Math::Vector3& right);
	extern Math::Vector3 operator *		 (const Math::Vector3& left, float					   right);
	extern Math::Vector3& operator *=	 (Math::Vector3& left, float right);

	//Vector4 Functions
	extern void	GetVector4TransformMatrix(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matrix);
	extern void	GetVector4TransformToScreen(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matView, const Math::Matrix& matProj, const Math::Matrix& matViewport);
	extern void	GetVector4TransformToScreen(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matWorld, const Math::Matrix& matView, const Math::Matrix& matProj, const Math::Matrix& matViewport);
	extern Math::Vector4 operator *		 (float					left, const Math::Vector4& right);
	extern Math::Vector4 operator *		 (const Math::Vector4& left, float					   right);

	//Quaternion Functions
	extern void	GetQuaternionIdentity(Math::Quaternion& out);
	extern void GetQuaternionNormalize(Math::Quaternion& out, const Math::Quaternion& in);
	extern void GetQuaternionInverse(Math::Quaternion& out, const Math::Quaternion& in);
	extern void GetQuaternionRotation(Math::Quaternion& out, const Math::Vector3&    axis, float radian);
	extern void GetQuaternionSlerp(Math::Quaternion& out, const Math::Quaternion& start, const Math::Quaternion& end, float t);
	extern void GetMatrixFromQuaternion(Math::Matrix&	 out, const Math::Quaternion& in);

	//Matrix Functions
	extern void	GetMatrixIdentity(Math::Matrix&	 out)												   throw();
	extern void GetMatrixInverse(Math::Matrix&	 out, const Math::Matrix&  in)					   throw();
	extern void GetMatrixTranspose(Math::Matrix&	 out, const Math::Matrix&  in)					   throw();
	extern void GetMatrixRotationX(Math::Matrix&	 out, float radian) throw();
	extern void GetMatrixRotationY(Math::Matrix&	 out, float radian) throw();
	extern void GetMatrixRotationZ(Math::Matrix&	 out, float radian) throw();
	extern void GetMatrixRotationAxis(Math::Matrix&	 out, const Math::Vector3& axis, float radian) throw();
	extern void GetMatrixScale(Math::Matrix&	 out, const Math::Vector3& scale)				   throw();
	extern void GetMatrixTranslation(Math::Matrix&	 out, const Math::Vector3& position)			   throw();
	extern void GetQuaternionFromMatrix(Math::Quaternion& out, const Math::Matrix&  in)					   throw();

	//Convert Functions
	inline		 Math::Vector2& ToVector2(Math::Vector3&    in) throw() { return reinterpret_cast<Math::Vector2&>(in); }
	inline const Math::Vector2& ToVector2(const Math::Vector3&    in) throw() { return reinterpret_cast<const Math::Vector2&>(in); }
	inline		 Math::Vector2& ToVector2(Math::Vector4&    in) throw() { return reinterpret_cast<Math::Vector2&>(in); }
	inline const Math::Vector2& ToVector2(const Math::Vector4&	   in) throw() { return reinterpret_cast<const Math::Vector2&>(in); }
	inline		 Math::Vector2& ToVector2(Math::Quaternion& in) throw() { return reinterpret_cast<Math::Vector2&>(in); }
	inline const Math::Vector2& ToVector2(const Math::Quaternion& in) throw() { return reinterpret_cast<const Math::Vector2&>(in); }
	inline		 Math::Vector3& ToVector3(Math::Vector4&	   in) throw() { return reinterpret_cast<Math::Vector3&>(in); }
	inline const Math::Vector3& ToVector3(const Math::Vector4&	   in) throw() { return reinterpret_cast<const Math::Vector3&>(in); }
	inline		 Math::Vector3& ToVector3(Math::Quaternion& in) throw() { return reinterpret_cast<Math::Vector3&>(in); }
	inline const Math::Vector3& ToVector3(const Math::Quaternion& in) throw() { return reinterpret_cast<const Math::Vector3&>(in); }

#ifdef __D3DX9_H__
	//DirectX9 Convert Functions
	inline		 D3DXVECTOR2&	 ToDX9(Math::Vector2&    in) throw() { return reinterpret_cast<	     D3DXVECTOR2&   >(in); }
	inline const D3DXVECTOR2&	 ToDX9(const Math::Vector2&    in) throw() { return reinterpret_cast<const D3DXVECTOR2&   >(in); }
	inline		 D3DXVECTOR3&	 ToDX9(Math::Vector3&    in) throw() { return reinterpret_cast<	     D3DXVECTOR3&   >(in); }
	inline const D3DXVECTOR3&	 ToDX9(const Math::Vector3&    in) throw() { return reinterpret_cast<const D3DXVECTOR3&   >(in); }
	inline		 D3DXVECTOR4&	 ToDX9(Math::Vector4&    in) throw() { return reinterpret_cast<	     D3DXVECTOR4&   >(in); }
	inline const D3DXVECTOR4&	 ToDX9(const Math::Vector4&	in) throw() { return reinterpret_cast<const D3DXVECTOR4&   >(in); }
	inline		 D3DXQUATERNION& ToDX9(Math::Quaternion& in) throw() { return reinterpret_cast<		 D3DXQUATERNION&>(in); }
	inline const D3DXQUATERNION& ToDX9(const Math::Quaternion& in) throw() { return reinterpret_cast<const D3DXQUATERNION&>(in); }
	inline		 D3DXMATRIX&	 ToDX9(Math::Matrix&		in) throw() { return reinterpret_cast<		 D3DXMATRIX&	>(in); }
	inline const D3DXMATRIX&	 ToDX9(const Math::Matrix&		in) throw() { return reinterpret_cast<const D3DXMATRIX&	>(in); }
#endif
#ifdef __D3DX11_H__
	//DirectX11 Convert Functions
	inline		 XMFLOAT2& ToDX11(Math::Vector2&    in) { return reinterpret_cast<	    XMFLOAT2&>(in); }
	inline const XMFLOAT2& ToDX11(const Math::Vector2&    in) { return reinterpret_cast<const XMFLOAT2&>(in); }
	inline		 XMFLOAT3& ToDX11(Math::Vector3&    in) { return reinterpret_cast<	    XMFLOAT3&>(in); }
	inline const XMFLOAT3& ToDX11(const Math::Vector3&    in) { return reinterpret_cast<const XMFLOAT3&>(in); }
	inline		 XMFLOAT4& ToDX11(Math::Vector4&    in) { return reinterpret_cast<	    XMFLOAT4&>(in); }
	inline const XMFLOAT4& ToDX11(const Math::Vector4&	   in) { return reinterpret_cast<const XMFLOAT4&>(in); }
	inline		 XMFLOAT4& ToDX11(Math::Quaternion& in) { return reinterpret_cast<		XMFLOAT4&>(in); }
	inline const XMFLOAT4& ToDX11(const Math::Quaternion& in) { return reinterpret_cast<const XMFLOAT4&>(in); }
	inline		 XMMATRIX& ToDX11(Math::Matrix&	   in) { return reinterpret_cast<		XMMATRIX&>(in); }
	inline const XMMATRIX& ToDX11(const Math::Matrix&	   in) { return reinterpret_cast<const XMMATRIX&>(in); }
#endif
}

//**************************************************************************************************
//2�����x�N�g���\����
//ver1.0	��{�I�ȋ@�\��������
//
//ver1.1	�e��I�y���[�^�[���������ė��֐�������
struct Math::Vector2
{
	union
	{
		struct
		{
			float x, y;
		};

		float f32[2];
	};

	//�f�t�H���g�R���X�g���N�^
	Vector2(void) : x(), y() {}

	//�R���X�g���N�^
	Vector2(float x, float y) : x(x), y(y) {}

	//�R�s�[�R���X�g���N�^
	Vector2(const Math::Vector2& right) : x(right.x), y(right.y) {}

	//�f�X�g���N�^
	~Vector2(void) {}

	//�֐��Ăяo�����Z�q
	const Math::Vector2& operator ()(float x, float y)					  throw();

	//������Z�q
	const Math::Vector2& operator = (const Math::Vector2& right)		  throw();
	const Math::Vector2& operator = (const Math::Vector3& right)		  throw();
	const Math::Vector2& operator = (const Math::Vector4& right)		  throw();

	//���Z������Z�q
	const Math::Vector2& operator +=(const Math::Vector2& right)		  throw();
	const Math::Vector2& operator +=(const Math::Vector3& right)		  throw();
	const Math::Vector2& operator +=(const Math::Vector4& right)		  throw();

	//���Z������Z�q
	const Math::Vector2& operator -=(const Math::Vector2& right)		  throw();
	const Math::Vector2& operator -=(const Math::Vector3& right)		  throw();
	const Math::Vector2& operator -=(const Math::Vector4& right)		  throw();

	//�}�C�i�X�������Z�q
	Math::Vector2		 operator - (void)							const throw();

	//���Z���Z�q
	Math::Vector2		 operator + (const Math::Vector2& right)	const throw();
	Math::Vector2		 operator + (const Math::Vector3& right)	const throw();
	Math::Vector2		 operator + (const Math::Vector4& right)	const throw();

	//���Z���Z�q
	Math::Vector2		 operator - (const Math::Vector2& right)	const throw();
	Math::Vector2		 operator - (const Math::Vector3& right)	const throw();
	Math::Vector2		 operator - (const Math::Vector4& right)	const throw();

	//���ς��擾����֐�
	float					 Dot(const Math::Vector2& right)	const throw();

	//�O�ς��擾����֐�		 
	float					 Cross(const Math::Vector2& right)	const throw();

	//�x�N�g���̒������擾����֐�
	float					 Length(void)							const throw();
	float					 Length2(void)							const throw();

	//�x�N�g���̊p�x���擾����֐�
	float					 Angle(const Math::Vector2& target) const throw();
	float					 Angle2(const Math::Vector2& target) const throw();

	//�������擾����֐�
	float					 Distance(const Math::Vector2& target) const throw();
	float					 Distance2(const Math::Vector2& target) const throw();
};

//**************************************************************************************************
//3�����x�N�g���\����
//ver1.0	��{�I�ȋ@�\��������
//
//ver1.1	�e��I�y���[�^�[���������ė��֐�������	
struct Math::Vector3
{
	union
	{
		struct
		{
			float x, y, z;
		};

		float f32[3];
	};

	//�f�t�H���g�R���X�g���N�^
	Vector3(void) : x(), y(), z() {}

	//�R���X�g���N�^
	Vector3(float x, float y) : x(x), y(y), z()	  {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	//�R�s�[�R���X�g���N�^
	Vector3(const Math::Vector3& right) : x(right.x), y(right.y), z(right.z) {}

	//�f�X�g���N�^
	~Vector3(void) {}

	//�֐��Ăяo�����Z�q
	Math::Vector3& operator ()(float x, float y)					  throw();
	Math::Vector3& operator ()(float x, float y, float z)			  throw();

	//������Z�q
	const Math::Vector3& operator = (const Math::Vector2& right)		  throw();
	const Math::Vector3& operator = (const Math::Vector3& right)		  throw();
	const Math::Vector3& operator = (const Math::Vector4& right)		  throw();

	//���Z������Z�q
	const Math::Vector3& operator +=(const Math::Vector2& right)		  throw();
	const Math::Vector3& operator +=(const Math::Vector3& right)		  throw();
	const Math::Vector3& operator +=(const Math::Vector4& right)		  throw();

	//���Z������Z�q
	const Math::Vector3& operator -=(const Math::Vector2& right)		  throw();
	const Math::Vector3& operator -=(const Math::Vector3& right)		  throw();
	const Math::Vector3& operator -=(const Math::Vector4& right)		  throw();

	//�}�C�i�X�������Z�q
	Math::Vector3		 operator - ()									const throw();

	//���Z���Z�q
	Math::Vector3		 operator + (const Math::Vector2& right)	const throw();
	Math::Vector3		 operator + (const Math::Vector3& right)	const throw();
	Math::Vector3		 operator + (const Math::Vector4& right)	const throw();

	//���Z���Z�q
	Math::Vector3		 operator - (const Math::Vector2& right)	const throw();
	Math::Vector3		 operator - (const Math::Vector3& right)	const throw();
	Math::Vector3		 operator - (const Math::Vector4& right)	const throw();

	//���ς��擾����֐�
	float					 Dot(const Math::Vector3& right)  const throw();

	//�O�ς��擾����֐�		 
	Math::Vector3		 Cross(const Math::Vector3& right)  const throw();

	//�x�N�g���̒������擾����֐�
	float					 Length(void)							const throw();
	float					 Length2(void)							const throw();

	//�x�N�g���̊p�x���擾����֐�
	float					 Angle(const Math::Vector3& target) const throw();
	float					 Angle2(const Math::Vector3& target) const throw();

	//�������擾����֐�
	float					 Distance(const Math::Vector3& target) const throw();
	float					 Distance2(const Math::Vector3& target) const throw();

	// �ϊ��֐�
	Math::Vector2&		 ToVector2()										  throw() { return reinterpret_cast<Math::Vector2&>(*this); }
	const Math::Vector2& ToVector2()									const throw() { return reinterpret_cast<const Math::Vector2&>(*this); }
};


//**************************************************************************************************
//4�����x�N�g���\����
//ver1.0	��{�I�ȋ@�\��������
//
//ver1.1	�e��I�y���[�^�[���������ė��֐�������
struct Math::Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};

		float f32[4];
	};

	//�f�t�H���g�R���X�g���N�^
	Vector4(void) : x(), y(), z(), w() {}

	//�R���X�g���N�^
	Vector4(float x, float y) : x(x), y(y), z(), w()    {}
	Vector4(float x, float y, float z) : x(x), y(y), z(z), w()    {}
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	//�R�s�[�R���X�g���N�^
	Vector4(const Math::Vector4& right) : x(right.x), y(right.y), z(right.z), w(right.w) {}

	//�f�X�g���N�^
	~Vector4(void) {}

	//�֐��Ăяo�����Z�q
	const Math::Vector4& operator ()(float x, float y);
	const Math::Vector4& operator ()(float x, float y, float z);
	const Math::Vector4& operator ()(float x, float y, float z, float w);

	//�}�C�i�X�������Z�q
	Math::Vector4		 operator - (void)						    const throw();

	//������Z�q
	const Math::Vector4& operator = (const Math::Vector2& right)		  throw();
	const Math::Vector4& operator = (const Math::Vector3& right)		  throw();
	const Math::Vector4& operator = (const Math::Vector4& right)		  throw();

	//���Z������Z�q
	const Math::Vector4& operator +=(const Math::Vector2& right)		  throw();
	const Math::Vector4& operator +=(const Math::Vector3& right)		  throw();
	const Math::Vector4& operator +=(const Math::Vector4& right)		  throw();

	//���Z������Z�q
	const Math::Vector4& operator -=(const Math::Vector2& right)		  throw();
	const Math::Vector4& operator -=(const Math::Vector3& right)		  throw();
	const Math::Vector4& operator -=(const Math::Vector4& right)		  throw();

	//���Z���Z�q
	Math::Vector4		 operator + (const Math::Vector2& right)  const throw();
	Math::Vector4		 operator + (const Math::Vector3& right)  const throw();
	Math::Vector4		 operator + (const Math::Vector4& right)  const throw();

	//���Z���Z�q
	Math::Vector4		 operator - (const Math::Vector2& right)  const throw();
	Math::Vector4		 operator - (const Math::Vector3& right)  const throw();
	Math::Vector4		 operator - (const Math::Vector4& right)  const throw();

	//�L���X�g���Z�q
	inline operator Math::Quaternion&(void)							  throw() { return reinterpret_cast<Math::Quaternion&>(*this); }
	inline operator const Math::Quaternion&(void)					    const throw() { return reinterpret_cast<const Math::Quaternion&>(*this); }

	//���ς��擾����֐�
	float					 Dot(const Math::Vector4& right)  const throw();

	//�x�N�g���̒������擾����֐�
	float					 Length(void)							const throw();
	float					 Length2(void)							const throw();

	//�x�N�g���̊p�x���擾����֐�
	float					 Angle(const Math::Vector4& target) const throw();
	float					 Angle2(const Math::Vector4& target) const throw();

	//�������擾����֐�
	float					 Distance(const Math::Vector4& target) const throw();
	float					 Distance2(const Math::Vector4& target) const throw();

	// �ϊ��֐�
	Math::Vector2&		 ToVector2()										  throw() { return reinterpret_cast<Math::Vector2&>(*this); }
	const Math::Vector2& ToVector2()									const throw() { return reinterpret_cast<const Math::Vector2&>(*this); }
	Math::Vector3&		 ToVector3()										  throw() { return reinterpret_cast<Math::Vector3&>(*this); }
	const Math::Vector3& ToVector3()									const throw() { return reinterpret_cast<const Math::Vector3&>(*this); }
};

//**************************************************************************************************
//�N�H�[�^�j�I���\����
//ver1.0	��{�I�ȋ@�\��������
//ver1.1	�����̈��艻
struct Math::Quaternion
{
	union
	{
		struct
		{
			float x, y, z, w;
		};

		float f32[4];
	};

	//�f�t�H���g�R���X�g���N�^
	Quaternion(void) : x(), y(), z(), w() {}

	//�R���X�g���N�^
	Quaternion(const Math::Vector2& v) : x(v.x), y(v.y), z(), w() {}
	Quaternion(const Math::Vector3& v) : x(v.x), y(v.y), z(v.z), w() {}
	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	//�R�s�[�R���X�g���N�^
	Quaternion(const Math::Quaternion& right) : x(right.x), y(right.y), z(right.z), w(right.w) {}

	//�f�X�g���N�^
	~Quaternion(void) {}

	//�֐��Ăяo�����Z�q
	const Math::Quaternion& operator ()(float x, float y);
	const Math::Quaternion& operator ()(float x, float y, float z);
	const Math::Quaternion& operator ()(float x, float y, float z, float w);

	//��Z���Z�q
	Math::Quaternion		operator * (const Math::Quaternion& right) const;

	//��Z������Z�q
	const Math::Quaternion& operator *=(const Math::Quaternion& right);

	//�L���X�g���Z�q
	inline operator Math::Vector4&(void)	   { return reinterpret_cast<Math::Vector4&>(*this); }
	inline operator const Math::Vector4&(void) const { return reinterpret_cast<const Math::Vector4&>(*this); }

	//���ς����߂�֐�
	float				  Dot(const Math::Quaternion& right) const;

	//�������擾����֐�
	float				  Length(void) const;
	float				  Length2(void) const;
};

//**************************************************************************************************
//�}�g���b�N�X�N���X
//ver1.0
struct Math::Matrix
{
	union
	{
		struct
		{
			float m[4][4];
		};
		struct
		{
			Math::Vector4 row[4];
		};
	};

	//�f�t�H���g�R���X�g���N�^
	Matrix(void) : row() {}

	//�R���X�g���N�^
	Matrix(float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44);

	//�R�s�[�R���X�g���N�^
	Matrix(const Math::Matrix& right);

	//�f�X�g���N�^
	~Matrix(void) {}

	//���Z���Z�q
	Math::Matrix		operator + (const Math::Matrix& right) const;

	//���Z���Z�q
	Math::Matrix		operator - (const Math::Matrix& right) const;

	//��Z���Z�q
	Math::Matrix		operator * (const Math::Matrix& right) const;

	//���Z������Z�q
	const Math::Matrix& operator +=(const Math::Matrix& right);

	//���Z������Z�q
	const Math::Matrix& operator -=(const Math::Matrix& right);

	//��Z������Z�q
	const Math::Matrix& operator *=(const Math::Matrix& right);
};
#pragma once
#pragma warning( disable : 4351 )	// 初期化子内で配列の初期化をした場合に出る警告を解除

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
//2次元ベクトル構造体
//ver1.0	基本的な機能だけ実装
//
//ver1.1	各種オペレーターを実装して利便性を向上
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

	//デフォルトコンストラクタ
	Vector2(void) : x(), y() {}

	//コンストラクタ
	Vector2(float x, float y) : x(x), y(y) {}

	//コピーコンストラクタ
	Vector2(const Math::Vector2& right) : x(right.x), y(right.y) {}

	//デストラクタ
	~Vector2(void) {}

	//関数呼び出し演算子
	const Math::Vector2& operator ()(float x, float y)					  throw();

	//代入演算子
	const Math::Vector2& operator = (const Math::Vector2& right)		  throw();
	const Math::Vector2& operator = (const Math::Vector3& right)		  throw();
	const Math::Vector2& operator = (const Math::Vector4& right)		  throw();

	//加算代入演算子
	const Math::Vector2& operator +=(const Math::Vector2& right)		  throw();
	const Math::Vector2& operator +=(const Math::Vector3& right)		  throw();
	const Math::Vector2& operator +=(const Math::Vector4& right)		  throw();

	//減算代入演算子
	const Math::Vector2& operator -=(const Math::Vector2& right)		  throw();
	const Math::Vector2& operator -=(const Math::Vector3& right)		  throw();
	const Math::Vector2& operator -=(const Math::Vector4& right)		  throw();

	//マイナス符号演算子
	Math::Vector2		 operator - (void)							const throw();

	//加算演算子
	Math::Vector2		 operator + (const Math::Vector2& right)	const throw();
	Math::Vector2		 operator + (const Math::Vector3& right)	const throw();
	Math::Vector2		 operator + (const Math::Vector4& right)	const throw();

	//減算演算子
	Math::Vector2		 operator - (const Math::Vector2& right)	const throw();
	Math::Vector2		 operator - (const Math::Vector3& right)	const throw();
	Math::Vector2		 operator - (const Math::Vector4& right)	const throw();

	//内積を取得する関数
	float					 Dot(const Math::Vector2& right)	const throw();

	//外積を取得する関数		 
	float					 Cross(const Math::Vector2& right)	const throw();

	//ベクトルの長さを取得する関数
	float					 Length(void)							const throw();
	float					 Length2(void)							const throw();

	//ベクトルの角度を取得する関数
	float					 Angle(const Math::Vector2& target) const throw();
	float					 Angle2(const Math::Vector2& target) const throw();

	//距離を取得する関数
	float					 Distance(const Math::Vector2& target) const throw();
	float					 Distance2(const Math::Vector2& target) const throw();
};

//**************************************************************************************************
//3次元ベクトル構造体
//ver1.0	基本的な機能だけ実装
//
//ver1.1	各種オペレーターを実装して利便性を向上	
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

	//デフォルトコンストラクタ
	Vector3(void) : x(), y(), z() {}

	//コンストラクタ
	Vector3(float x, float y) : x(x), y(y), z()	  {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	//コピーコンストラクタ
	Vector3(const Math::Vector3& right) : x(right.x), y(right.y), z(right.z) {}

	//デストラクタ
	~Vector3(void) {}

	//関数呼び出し演算子
	Math::Vector3& operator ()(float x, float y)					  throw();
	Math::Vector3& operator ()(float x, float y, float z)			  throw();

	//代入演算子
	const Math::Vector3& operator = (const Math::Vector2& right)		  throw();
	const Math::Vector3& operator = (const Math::Vector3& right)		  throw();
	const Math::Vector3& operator = (const Math::Vector4& right)		  throw();

	//加算代入演算子
	const Math::Vector3& operator +=(const Math::Vector2& right)		  throw();
	const Math::Vector3& operator +=(const Math::Vector3& right)		  throw();
	const Math::Vector3& operator +=(const Math::Vector4& right)		  throw();

	//減算代入演算子
	const Math::Vector3& operator -=(const Math::Vector2& right)		  throw();
	const Math::Vector3& operator -=(const Math::Vector3& right)		  throw();
	const Math::Vector3& operator -=(const Math::Vector4& right)		  throw();

	//マイナス符号演算子
	Math::Vector3		 operator - ()									const throw();

	//加算演算子
	Math::Vector3		 operator + (const Math::Vector2& right)	const throw();
	Math::Vector3		 operator + (const Math::Vector3& right)	const throw();
	Math::Vector3		 operator + (const Math::Vector4& right)	const throw();

	//減算演算子
	Math::Vector3		 operator - (const Math::Vector2& right)	const throw();
	Math::Vector3		 operator - (const Math::Vector3& right)	const throw();
	Math::Vector3		 operator - (const Math::Vector4& right)	const throw();

	//内積を取得する関数
	float					 Dot(const Math::Vector3& right)  const throw();

	//外積を取得する関数		 
	Math::Vector3		 Cross(const Math::Vector3& right)  const throw();

	//ベクトルの長さを取得する関数
	float					 Length(void)							const throw();
	float					 Length2(void)							const throw();

	//ベクトルの角度を取得する関数
	float					 Angle(const Math::Vector3& target) const throw();
	float					 Angle2(const Math::Vector3& target) const throw();

	//距離を取得する関数
	float					 Distance(const Math::Vector3& target) const throw();
	float					 Distance2(const Math::Vector3& target) const throw();

	// 変換関数
	Math::Vector2&		 ToVector2()										  throw() { return reinterpret_cast<Math::Vector2&>(*this); }
	const Math::Vector2& ToVector2()									const throw() { return reinterpret_cast<const Math::Vector2&>(*this); }
};


//**************************************************************************************************
//4次元ベクトル構造体
//ver1.0	基本的な機能だけ実装
//
//ver1.1	各種オペレーターを実装して利便性を向上
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

	//デフォルトコンストラクタ
	Vector4(void) : x(), y(), z(), w() {}

	//コンストラクタ
	Vector4(float x, float y) : x(x), y(y), z(), w()    {}
	Vector4(float x, float y, float z) : x(x), y(y), z(z), w()    {}
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	//コピーコンストラクタ
	Vector4(const Math::Vector4& right) : x(right.x), y(right.y), z(right.z), w(right.w) {}

	//デストラクタ
	~Vector4(void) {}

	//関数呼び出し演算子
	const Math::Vector4& operator ()(float x, float y);
	const Math::Vector4& operator ()(float x, float y, float z);
	const Math::Vector4& operator ()(float x, float y, float z, float w);

	//マイナス符号演算子
	Math::Vector4		 operator - (void)						    const throw();

	//代入演算子
	const Math::Vector4& operator = (const Math::Vector2& right)		  throw();
	const Math::Vector4& operator = (const Math::Vector3& right)		  throw();
	const Math::Vector4& operator = (const Math::Vector4& right)		  throw();

	//加算代入演算子
	const Math::Vector4& operator +=(const Math::Vector2& right)		  throw();
	const Math::Vector4& operator +=(const Math::Vector3& right)		  throw();
	const Math::Vector4& operator +=(const Math::Vector4& right)		  throw();

	//減算代入演算子
	const Math::Vector4& operator -=(const Math::Vector2& right)		  throw();
	const Math::Vector4& operator -=(const Math::Vector3& right)		  throw();
	const Math::Vector4& operator -=(const Math::Vector4& right)		  throw();

	//加算演算子
	Math::Vector4		 operator + (const Math::Vector2& right)  const throw();
	Math::Vector4		 operator + (const Math::Vector3& right)  const throw();
	Math::Vector4		 operator + (const Math::Vector4& right)  const throw();

	//減算演算子
	Math::Vector4		 operator - (const Math::Vector2& right)  const throw();
	Math::Vector4		 operator - (const Math::Vector3& right)  const throw();
	Math::Vector4		 operator - (const Math::Vector4& right)  const throw();

	//キャスト演算子
	inline operator Math::Quaternion&(void)							  throw() { return reinterpret_cast<Math::Quaternion&>(*this); }
	inline operator const Math::Quaternion&(void)					    const throw() { return reinterpret_cast<const Math::Quaternion&>(*this); }

	//内積を取得する関数
	float					 Dot(const Math::Vector4& right)  const throw();

	//ベクトルの長さを取得する関数
	float					 Length(void)							const throw();
	float					 Length2(void)							const throw();

	//ベクトルの角度を取得する関数
	float					 Angle(const Math::Vector4& target) const throw();
	float					 Angle2(const Math::Vector4& target) const throw();

	//距離を取得する関数
	float					 Distance(const Math::Vector4& target) const throw();
	float					 Distance2(const Math::Vector4& target) const throw();

	// 変換関数
	Math::Vector2&		 ToVector2()										  throw() { return reinterpret_cast<Math::Vector2&>(*this); }
	const Math::Vector2& ToVector2()									const throw() { return reinterpret_cast<const Math::Vector2&>(*this); }
	Math::Vector3&		 ToVector3()										  throw() { return reinterpret_cast<Math::Vector3&>(*this); }
	const Math::Vector3& ToVector3()									const throw() { return reinterpret_cast<const Math::Vector3&>(*this); }
};

//**************************************************************************************************
//クォータニオン構造体
//ver1.0	基本的な機能だけ実装
//ver1.1	挙動の安定化
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

	//デフォルトコンストラクタ
	Quaternion(void) : x(), y(), z(), w() {}

	//コンストラクタ
	Quaternion(const Math::Vector2& v) : x(v.x), y(v.y), z(), w() {}
	Quaternion(const Math::Vector3& v) : x(v.x), y(v.y), z(v.z), w() {}
	Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	//コピーコンストラクタ
	Quaternion(const Math::Quaternion& right) : x(right.x), y(right.y), z(right.z), w(right.w) {}

	//デストラクタ
	~Quaternion(void) {}

	//関数呼び出し演算子
	const Math::Quaternion& operator ()(float x, float y);
	const Math::Quaternion& operator ()(float x, float y, float z);
	const Math::Quaternion& operator ()(float x, float y, float z, float w);

	//乗算演算子
	Math::Quaternion		operator * (const Math::Quaternion& right) const;

	//乗算代入演算子
	const Math::Quaternion& operator *=(const Math::Quaternion& right);

	//キャスト演算子
	inline operator Math::Vector4&(void)	   { return reinterpret_cast<Math::Vector4&>(*this); }
	inline operator const Math::Vector4&(void) const { return reinterpret_cast<const Math::Vector4&>(*this); }

	//内積を求める関数
	float				  Dot(const Math::Quaternion& right) const;

	//長さを取得する関数
	float				  Length(void) const;
	float				  Length2(void) const;
};

//**************************************************************************************************
//マトリックスクラス
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

	//デフォルトコンストラクタ
	Matrix(void) : row() {}

	//コンストラクタ
	Matrix(float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44);

	//コピーコンストラクタ
	Matrix(const Math::Matrix& right);

	//デストラクタ
	~Matrix(void) {}

	//加算演算子
	Math::Matrix		operator + (const Math::Matrix& right) const;

	//減算演算子
	Math::Matrix		operator - (const Math::Matrix& right) const;

	//乗算演算子
	Math::Matrix		operator * (const Math::Matrix& right) const;

	//加算代入演算子
	const Math::Matrix& operator +=(const Math::Matrix& right);

	//減算代入演算子
	const Math::Matrix& operator -=(const Math::Matrix& right);

	//乗算代入演算子
	const Math::Matrix& operator *=(const Math::Matrix& right);
};
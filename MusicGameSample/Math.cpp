#include <math.h>
#include "Math.h"

//staticフィールドの初期化
const Math::Vector3 Math::XAXIS = Math::Vector3(1.0f, 0.0f, 0.0f);
const Math::Vector3 Math::YAXIS = Math::Vector3(0.0f, 1.0f, 0.0f);
const Math::Vector3 Math::ZAXIS = Math::Vector3(0.0f, 0.0f, 1.0f);

//--------------------------------------------------------------------------------------------------
//
//
//											Vector2
//
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      参照
//Param:       x, y:要素
const Math::Vector2& Math::Vector2::operator ()(const float x, const float y)
{
	this->x = x;
	this->y = y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 代入演算子
//Return:      演算結果
//Param:       right:右辺値
const Math::Vector2& Math::Vector2::operator= (const Math::Vector2& right)
{
	//自己代入チェック
	if (this == &right) { return *this; }
	this->x = right.x;
	this->y = right.y;

	return *this;
}
const Math::Vector2& Math::Vector2::operator= (const Math::Vector3& right)
{
	this->x = right.x;
	this->y = right.y;

	return *this;
}
const Math::Vector2& Math::Vector2::operator= (const Math::Vector4& right)
{
	this->x = right.x;
	this->y = right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: マイナス符号演算子
//Return:      計算結果
//Param:       無し
Math::Vector2 Math::Vector2::operator -() const
{
	return Vector2(-x, -y);
}

//--------------------------------------------------------------------------------------------------
//Description: 加算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector2 Math::Vector2::operator +(const Vector2& right) const
{
	return Vector2(x + right.x, y + right.y);
}
Math::Vector2 Math::Vector2::operator +(const Vector3& right) const
{
	return Vector2(x + right.x, y + right.y);
}
Math::Vector2 Math::Vector2::operator +(const Vector4& right) const
{
	return Vector2(x + right.x, y + right.y);
}

//--------------------------------------------------------------------------------------------------
//Description: 減算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector2 Math::Vector2::operator -(const Vector2& right) const
{
	return Vector2(x - right.x, y - right.y);
}
Math::Vector2 Math::Vector2::operator -(const Vector3& right) const
{
	return Vector2(x - right.x, y - right.y);
}
Math::Vector2 Math::Vector2::operator -(const Vector4& right) const
{
	return Vector2(x - right.x, y - right.y);
}

//--------------------------------------------------------------------------------------------------
//Description: 加算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector2& Math::Vector2::operator +=(const Vector2& right)
{
	x += right.x;
	y += right.y;

	return *this;
}
const Math::Vector2& Math::Vector2::operator +=(const Vector3& right)
{
	x += right.x;
	y += right.y;

	return *this;
}
const Math::Vector2& Math::Vector2::operator +=(const Vector4& right)
{
	x += right.x;
	y += right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector2& Math::Vector2::operator -=(const Vector2& right)
{
	x -= right.x;
	y -= right.y;

	return *this;
}
const Math::Vector2& Math::Vector2::operator -=(const Vector3& right)
{
	x -= right.x;
	y -= right.y;

	return *this;
}
const Math::Vector2& Math::Vector2::operator -=(const Vector4& right)
{
	x -= right.x;
	y -= right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 内積を取得する関数
//Return:      内積
//Param:       right:右辺値
float Math::Vector2::Dot(const Math::Vector2& right) const
{
	return x * right.x + y * right.y;
}

//--------------------------------------------------------------------------------------------------
//Description: 外積を取得する関数
//Return:      外積(定数)
//Param:       right:右辺値
float Math::Vector2::Cross(const Math::Vector2& right) const
{
	const float src_len = this->Length();
	const float trg_len = right.Length();
	const float angle = acosf(this->Dot(right) / (src_len * trg_len));

	return src_len * trg_len * sinf(angle);
}

//--------------------------------------------------------------------------------------------------
//Description: 長さを取得する関数
//Return:      ベクトルの長さ
//Param:       無し
float Math::Vector2::Length(void) const
{
	return sqrt(Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: 長さの2乗を取得する関数
//Return:      ベクトルの長さの2乗
//Param:       無し
float Math::Vector2::Length2(void) const
{
	return x * x + y * y;
}

//--------------------------------------------------------------------------------------------------
//Description: なす角を取得する関数
//Return:      角度
//Param:       right:右辺値
float Math::Vector2::Angle(const Math::Vector2& right) const
{
	const float cos_val = Dot(right) / (Length() * right.Length());
	return acosf(cos_val);
}

//--------------------------------------------------------------------------------------------------
//Description: なす角を取得する関数( -π～π )
//Return:      角度( ラジアン )
//Param:       right:右辺値
float Math::Vector2::Angle2(const Math::Vector2& right) const
{
	const float cross = this->Cross(right);

	//外積値が0以下なら時計回り方向
	if (cross < 0)
	{
		return Angle(right);
	}
	//0以上なら反時計回り方向
	else if (cross > 0)
	{
		return -Angle(right);
	}

	//同じ方向ならば0を返す
	return 0.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 距離を取得する関数
//Return:      距離
//Param:       target:対象
float Math::Vector2::Distance(const Math::Vector2& target) const
{
	return sqrt(this->Distance2(target));
}

//--------------------------------------------------------------------------------------------------
//Description: 距離の2乗を取得する関数
//Return:      距離
//Param:       target:対象
float Math::Vector2::Distance2(const Math::Vector2& target) const
{
	return target.x - x * target.y - y;
}

//--------------------------------------------------------------------------------------------------
//
//
//											Vector3
//
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Description: マイナス符号演算子
//Return:      計算結果
//Param:       無し
Math::Vector3 Math::Vector3::operator -(void) const
{
	return Math::Vector3(-x, -y, -z);
}

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      自身の参照
//Param:       x, y:要素
Math::Vector3& Math::Vector3::operator ()(float x, float y)
{
	this->x = x;
	this->y = y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      自身の参照
//Param:       x, y, z:要素
Math::Vector3& Math::Vector3::operator ()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 代入演算子
//Return:      自身の参照
//Param:       right:右辺値
const Math::Vector3& Math::Vector3::operator =(const Math::Vector2& right)
{
	//自己代入チェック
	this->x = right.x;
	this->y = right.y;

	return *this;
}
const Math::Vector3& Math::Vector3::operator =(const Math::Vector3& right)
{
	//自己代入チェック
	if (this == &right) return *this;
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;

	return *this;
}
const Math::Vector3& Math::Vector3::operator =(const Math::Vector4& right)
{
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector3& Math::Vector3::operator +=(const Math::Vector2& right)
{
	this->x += right.x;
	this->y += right.y;

	return *this;
}
const Math::Vector3& Math::Vector3::operator +=(const Math::Vector3& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;

	return *this;
}
const Math::Vector3& Math::Vector3::operator +=(const Math::Vector4& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector3& Math::Vector3::operator -=(const Math::Vector2& right)
{
	this->x -= right.x;
	this->y -= right.y;

	return *this;
}
const Math::Vector3& Math::Vector3::operator -=(const Math::Vector3& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;

	return *this;
}
const Math::Vector3& Math::Vector3::operator -=(const Math::Vector4& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector3 Math::Vector3::operator +(const Math::Vector2& right) const
{
	return Vector3(x + right.x, y + right.y, this->z);
}
Math::Vector3 Math::Vector3::operator +(const Math::Vector3& right) const
{
	return Vector3(x + right.x, y + right.y, z + right.z);
}
Math::Vector3 Math::Vector3::operator +(const Math::Vector4& right) const
{
	return Vector3(x + right.x, y + right.y, z + right.z);
}

//--------------------------------------------------------------------------------------------------
//Description: 減算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector3 Math::Vector3::operator -(const Math::Vector2& right) const
{
	return Vector3(x - right.x, y - right.y, this->z);
}
Math::Vector3 Math::Vector3::operator -(const Math::Vector3& right) const
{
	return Vector3(x - right.x, y - right.y, z - right.z);
}
Math::Vector3 Math::Vector3::operator -(const Math::Vector4& right) const
{
	return Vector3(x - right.x, y - right.y, z - right.z);
}

//--------------------------------------------------------------------------------------------------
//Description: 長さを取得する関数
//Return:      ベクトルの長さ
//Param:       無し
float Math::Vector3::Length() const
{
	return sqrt(Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: 長さの2乗を取得する関数
//Return:      ベクトルの長さの2乗
//Param:       無し
float Math::Vector3::Length2() const
{
	return x * x + y * y + z * z;
}

//--------------------------------------------------------------------------------------------------
//Description: 2点間の距離を取得する関数
//Return:      距離
//Param:       to:対象の位置ベクトル
float Math::Vector3::Distance(const Math::Vector3& to) const
{
	return sqrt((to.x - x) * (to.x - x) + (to.y - y) * (to.y - y) + (to.z - z) * (to.z - z));
}

//--------------------------------------------------------------------------------------------------
//Description: なす角を取得する関数
//Return:      角度
//Param:       right:右辺値
float Math::Vector3::Angle(const Math::Vector3& right) const
{
	const float cos_val = Dot(right) / (Length() * right.Length());
	return acosf(cos_val);
}

//--------------------------------------------------------------------------------------------------
//Description: 内積を取得する関数
//Return:      内積
//Param:       right:右辺値
float Math::Vector3::Dot(const Vector3& right) const
{
	return x * right.x + y * right.y + z * right.z;
}

//--------------------------------------------------------------------------------------------------
//
//
//											Vector4
//
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      自身の参照
//Param:       x, y:要素
const Math::Vector4& Math::Vector4::operator ()(float x, float y)
{
	this->x = x;
	this->y = y;

	return *this;
}
//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      自身の参照
//Param:       x, y, z:要素
const Math::Vector4& Math::Vector4::operator ()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      自身の参照
//Param:       x, y, z, w:要素
const Math::Vector4& Math::Vector4::operator ()(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 代入演算子
//Return:      自身の参照
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator =(const Math::Vector2& right)
{
	//自己代入チェック
	this->x = right.x;
	this->y = right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 代入演算子
//Return:      自身の参照
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator =(const Math::Vector3& right)
{
	//自己代入チェック
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 代入演算子
//Return:      自身の参照
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator =(const Math::Vector4& right)
{
	//自己代入チェック
	if (this == &right) return *this;
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
	this->w = right.w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator +=(const Vector2& right)
{
	this->x += right.x;
	this->y += right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator +=(const Vector3& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator +=(const Vector4& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	this->w += right.w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator -=(const Math::Vector2& right)
{
	this->x -= right.x;
	this->y -= right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator -=(const Math::Vector3& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Vector4& Math::Vector4::operator -=(const Vector4& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	this->w -= right.w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector4 Math::Vector4::operator +(const Math::Vector2& right) const
{
	Math::Vector4 ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector4 Math::Vector4::operator +(const Math::Vector3& right) const
{
	Math::Vector4 ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector4 Math::Vector4::operator +(const Math::Vector4& right) const
{
	Math::Vector4 ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector4 Math::Vector4::operator -(const Math::Vector2& right) const
{
	Math::Vector4 ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector4 Math::Vector4::operator -(const Math::Vector3& right) const
{
	Math::Vector4 ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Vector4 Math::Vector4::operator -(const Math::Vector4& right) const
{
	Math::Vector4 ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: ベクトルの絶対値を取得する関数
//Return:      ベクトルの絶対値
//Param:       無し
float Math::Vector4::Length(void) const
{
	return sqrt(this->Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: ベクトルの絶対値を取得する関数
//Return:      ベクトルの絶対値
//Param:       無し
float Math::Vector4::Length2(void) const
{
	return x * x + y * y + z * z + w * w;
}

//--------------------------------------------------------------------------------------------------
//
//
//											Quaternion
//
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      演算結果
//Param:       x, y:格納する値
const Math::Quaternion& Math::Quaternion::operator()(float x, float y)
{
	this->x = x;
	this->y = y;
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      演算結果
//Param:       x, y, z:格納する値
const Math::Quaternion& Math::Quaternion::operator()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 関数呼び出し演算子
//Return:      演算結果
//Param:       x, y, z, w:格納する値
const Math::Quaternion& Math::Quaternion::operator()(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Quaternion Math::Quaternion::operator *(const Math::Quaternion& right) const
{
	Math::Quaternion ret;

	ret(right.y * z - right.z * y + right.w * x + w * right.x,
		right.z * x - right.x * z + right.w * y + w * right.y,
		right.x * y - right.y * x + right.w * z + w * right.z,
		w * right.w - x * right.x + y * right.y + z * right.z);

	return ret;
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算代入演算子
//Return:      計算結果
//Param:       right:右辺値
const Math::Quaternion& Math::Quaternion::operator *=(const Math::Quaternion& right)
{
	(*this)(right.y * z - right.z * y + right.w * x + w * right.x,		// v1×v2 + w1*v2 + w2*v1
		right.z * x - right.x * z + right.w * y + w * right.y,
		right.x * y - right.y * x + right.w * z + w * right.z,
		w * right.w - x * right.x + y * right.y + z * right.z);	// w1*w2 - (v1・v2)
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 内積を求める関数
//Return:      内積
//Param:       right:右辺値
float Math::Quaternion::Dot(const Math::Quaternion& right) const
{
	return x * right.x + y * right.y + z * right.z * w + right.w;
}


//--------------------------------------------------------------------------------------------------
//Description: 長さを取得する関数
//Return:      クォータニオンの長さ
//Param:       無し
float Math::Quaternion::Length(void) const
{
	return sqrt(this->Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: 長さの２乗を取得する関数
//Return:      クォータニオンの長さの２乗
//Param:       無し
float Math::Quaternion::Length2(void) const
{
	return x * x + y * y + z * z + w * w;
}

//--------------------------------------------------------------------------------------------------
//Description: コンストラクタ
//Return:      無し
//Param:       _~~:番号に対応した要素
Math::Matrix::Matrix(float _11, float _12, float _13, float _14,
	float _21, float _22, float _23, float _24,
	float _31, float _32, float _33, float _34,
	float _41, float _42, float _43, float _44)
{
	row[0](_11, _12, _13, _14);
	row[1](_21, _22, _23, _24);
	row[2](_31, _32, _33, _34);
	row[3](_41, _42, _43, _44);
}

//--------------------------------------------------------------------------------------------------
//Description: コンストラクタ
//Return:      無し
//Param:       _~~:番号に対応した要素
Math::Matrix::Matrix(const Matrix& right)
{
	row[0] = right.row[0];
	row[1] = right.row[1];
	row[2] = right.row[2];
	row[3] = right.row[3];
}

//--------------------------------------------------------------------------------------------------
//Description: 加算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Matrix Math::Matrix::operator +(const Math::Matrix& right) const
{
	Math::Matrix ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Matrix Math::Matrix::operator -(const Math::Matrix& right) const
{
	Math::Matrix ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       right:右辺値
Math::Matrix Math::Matrix::operator *(const Math::Matrix& right) const
{
	Math::Matrix ret = *this;
	return ret *= right;
}

//--------------------------------------------------------------------------------------------------
//Description: 加算代入演算子
//Return:      無し
//Param:       right:右辺値
const Math::Matrix& Math::Matrix::operator +=(const Math::Matrix& right)
{
	m[0][0] = m[0][0] + right.m[0][0];
	m[0][1] = m[0][1] + right.m[0][1];
	m[0][2] = m[0][2] + right.m[0][2];
	m[0][3] = m[0][3] + right.m[0][3];

	m[1][0] = m[1][0] + right.m[1][0];
	m[1][1] = m[1][1] + right.m[1][1];
	m[1][2] = m[1][2] + right.m[1][2];
	m[1][3] = m[1][3] + right.m[1][3];

	m[2][0] = m[2][0] + right.m[2][0];
	m[2][1] = m[2][1] + right.m[2][1];
	m[2][2] = m[2][2] + right.m[2][2];
	m[2][3] = m[2][3] + right.m[2][3];

	m[3][0] = m[3][0] + right.m[3][0];
	m[3][1] = m[3][1] + right.m[3][1];
	m[3][2] = m[3][2] + right.m[3][2];
	m[3][3] = m[3][3] + right.m[3][3];

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 減算代入演算子
//Return:      無し
//Param:       right:右辺値
const Math::Matrix& Math::Matrix::operator -=(const Math::Matrix& right)
{
	m[0][0] = m[0][0] - right.m[0][0];
	m[0][1] = m[0][1] - right.m[0][1];
	m[0][2] = m[0][2] - right.m[0][2];
	m[0][3] = m[0][3] - right.m[0][3];

	m[1][0] = m[1][0] - right.m[1][0];
	m[1][1] = m[1][1] - right.m[1][1];
	m[1][2] = m[1][2] - right.m[1][2];
	m[1][3] = m[1][3] - right.m[1][3];

	m[2][0] = m[2][0] - right.m[2][0];
	m[2][1] = m[2][1] - right.m[2][1];
	m[2][2] = m[2][2] - right.m[2][2];
	m[2][3] = m[2][3] - right.m[2][3];

	m[3][0] = m[3][0] - right.m[3][0];
	m[3][1] = m[3][1] - right.m[3][1];
	m[3][2] = m[3][2] - right.m[3][2];
	m[3][3] = m[3][3] - right.m[3][3];

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算代入演算子
//Return:      無し
//Param:       right:右辺値
const Math::Matrix& Math::Matrix::operator *=(const Math::Matrix& right)
{
	m[0][0] = m[0][0] * right.m[0][0] + m[0][1] * right.m[1][0] + m[0][2] * right.m[2][0] + m[0][3] * right.m[3][0];
	m[0][1] = m[0][0] * right.m[0][1] + m[0][1] * right.m[1][1] + m[0][2] * right.m[2][1] + m[0][3] * right.m[3][1];
	m[0][2] = m[0][0] * right.m[0][2] + m[0][1] * right.m[1][2] + m[0][2] * right.m[2][2] + m[0][3] * right.m[3][2];
	m[0][3] = m[0][0] * right.m[0][3] + m[0][1] * right.m[1][3] + m[0][2] * right.m[2][3] + m[0][3] * right.m[3][3];

	m[1][0] = m[1][0] * right.m[0][0] + m[1][1] * right.m[1][0] + m[1][2] * right.m[2][0] + m[1][3] * right.m[3][0];
	m[1][1] = m[1][0] * right.m[0][1] + m[1][1] * right.m[1][1] + m[1][2] * right.m[2][1] + m[1][3] * right.m[3][1];
	m[1][2] = m[1][0] * right.m[0][2] + m[1][1] * right.m[1][2] + m[1][2] * right.m[2][2] + m[1][3] * right.m[3][2];
	m[1][3] = m[1][0] * right.m[0][3] + m[1][1] * right.m[1][3] + m[1][2] * right.m[2][3] + m[1][3] * right.m[3][3];

	m[2][0] = m[2][0] * right.m[0][0] + m[2][1] * right.m[1][0] + m[2][2] * right.m[2][0] + m[2][3] * right.m[3][0];
	m[2][1] = m[2][0] * right.m[0][1] + m[2][1] * right.m[1][1] + m[2][2] * right.m[2][1] + m[2][3] * right.m[3][1];
	m[2][2] = m[2][0] * right.m[0][2] + m[2][1] * right.m[1][2] + m[2][2] * right.m[2][2] + m[2][3] * right.m[3][2];
	m[2][3] = m[2][0] * right.m[0][3] + m[2][1] * right.m[1][3] + m[2][2] * right.m[2][3] + m[2][3] * right.m[3][3];

	m[3][0] = m[3][0] * right.m[0][0] + m[3][1] * right.m[1][0] + m[3][2] * right.m[2][0] + m[3][3] * right.m[3][0];
	m[3][1] = m[3][0] * right.m[0][1] + m[3][1] * right.m[1][1] + m[3][2] * right.m[2][1] + m[3][3] * right.m[3][1];
	m[3][2] = m[3][0] * right.m[0][2] + m[3][1] * right.m[1][2] + m[3][2] * right.m[2][2] + m[3][3] * right.m[3][2];
	m[3][3] = m[3][0] * right.m[0][3] + m[3][1] * right.m[1][3] + m[3][2] * right.m[2][3] + m[3][3] * right.m[3][3];

	return *this;
}

//--------------------------------------------------------------------------------------------------
//
//
//										Grobal Functions
//
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Description: 単位ベクトルを取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象
void Math::Normalize(Math::Vector2& target)
{
	const float length = target.Length();

	//長さが0ならば正規化の必要なし
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: 単位ベクトルを取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象
void Math::Normalize(Math::Vector3& target)
{
	const float length = target.Length();

	//長さが0ならば正規化の必要なし
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
	target.z /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: 単位ベクトルを取得する関数
//Return:      無し
//Param:       target:対象
void Math::Normalize(Math::Vector4& target)
{
	const float length = target.Length();

	//長さが0の場合は正規化できない
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
	target.z /= length;
	target.w /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: 正規化する関数
//Return:      無し
//Param:       target:対象
void Math::Normalize(Math::Quaternion& target)
{
	const float length = target.Length();

	//長さが0ならば正規化の必要なし
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
	target.z /= length;
	target.w /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: ベクトルを回転させる関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, radian:回転角
void Math::GetVector2Rotation(Math::Vector2& out, const Math::Vector2& in, float radian)
{
	const float sin_val = sin(radian);
	const float cos_val = cos(radian);
	out.x = cos_val - sin_val;
	out.y = sin_val + cos_val;
}

//--------------------------------------------------------------------------------------------------
//Description: ベクトルを行列で変換する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matrix:行列
void Math::GetVector2TransformMatrix(Math::Vector2& out, const Math::Vector3& in, const Math::Matrix& matrix)
{
	out(in.x * matrix.m[0][0] + in.y * matrix.m[1][0] + in.z * matrix.m[2][0] + matrix.m[3][0],
		in.x * matrix.m[0][1] + in.y * matrix.m[1][1] + in.z * matrix.m[2][1] + matrix.m[3][1]);
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       out:ここに結果が出力される, left:左辺値, right:右辺値
Math::Vector2 Math::operator *(float left, const Math::Vector2& right)
{
	return Math::Vector2(left * right.x, left * right.y);
}
Math::Vector2 Math::operator *(const Math::Vector2& left, float right)
{
	return Math::Vector2(left.x * right, left.y * right);
}



//--------------------------------------------------------------------------------------------------
//Description: 外積を取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される, left:左辺値, right:右辺値
void Math::GetVector3Cross(Math::Vector3& out, const Math::Vector3& left, const Math::Vector3& right)
{
	out(left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
}

//--------------------------------------------------------------------------------------------------
//Description: x軸回転させる関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, radian:回転角度
void Math::GetVector3RotationX(Math::Vector3& out, const Math::Vector3& in, float radian)
{
	Math::Vector3 XAxis(1.0f, 0.0f, 0.0f);
	Math::GetVector3RotationAxis(out, in, XAxis, radian);
}

//--------------------------------------------------------------------------------------------------
//Description: y軸回転させる関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, radian:回転角度
void Math::GetVector3RotationY(Math::Vector3& out, const Math::Vector3& in, float radian)
{
	Math::Vector3 YAxis(0.0f, 1.0f, 0.0f);
	Math::GetVector3RotationAxis(out, in, YAxis, radian);
}

//--------------------------------------------------------------------------------------------------
//Description: z軸回転させる関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, radian:回転角度
void Math::GetVector3RotationZ(Math::Vector3& out, const Math::Vector3& in, float radian)
{
	Math::Vector3 ZAxis(0.0f, 0.0f, 1.0f);
	Math::GetVector3RotationAxis(out, in, ZAxis, radian);
}

//--------------------------------------------------------------------------------------------------
//Description: 任意軸回転させる関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, axis:回転軸, radian:回転角度
void Math::GetVector3RotationAxis(Math::Vector3& out, const Math::Vector3& in, const Math::Vector3& axis, float radian)
{
	Math::Quaternion quat;
	Math::GetQuaternionRotation(quat, axis, radian);
	Math::GetVector3RotationQuaternion(out, in, quat);
}

//--------------------------------------------------------------------------------------------------
//Description: クォータニオンで回転させる関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, quat:回転クォータニオン
void Math::GetVector3RotationQuaternion(Math::Vector3& out, const Math::Vector3& in, const Math::Quaternion& quat)
{
	//P' = Q * P * R;( RはQの共役四元数 )
	//1.P * R
	Math::Quaternion left = in;
	Math::Quaternion right(-quat.x, -quat.y, -quat.z, quat.w);
	Math::Quaternion result(right.y * left.z - right.z * left.y + right.w * left.x + left.w * right.x,
		right.z * left.x - right.x * left.z + right.w * left.y + left.w * right.y,
		right.x * left.y - right.y * left.x + right.w * left.z + left.w * right.z,
		left.w * right.w - left.x * right.x + left.y * right.y + left.z * right.z);

	//2.Q * PR;
	right = result;
	left = quat;
	result(right.y * left.z - right.z * left.y + right.w * left.x + left.w * right.x,
		right.z * left.x - right.x * left.z + right.w * left.y + left.w * right.y,
		right.x * left.y - right.y * left.x + right.w * left.z + left.w * right.z,
		left.w * right.w - left.x * right.x + left.y * right.y + left.z * right.z);

	out(result.x, result.y, result.z);
}

//--------------------------------------------------------------------------------------------------
//Description: 球面線形補間する関数
//Return:      無し
//Param:       out:ここに結果が代入される, start:補間開始地点, end:補間終了地点, t:補間係数( 0~1 )
void Math::GetVector3Slerp(Math::Vector3& out, const Math::Vector3& start, const Math::Vector3& end, float t)
{
	Math::Quaternion s(start), e(end);
	Math::GetQuaternionSlerp(s, s, e, t);
	out(s.x, s.y, s.z);
}

//--------------------------------------------------------------------------------------------------
//Description: ベクトルを行列で変換する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matrix:行列
void Math::GetVector3TransformMatrix(Math::Vector3& out, const Math::Vector3& in, const Math::Matrix& matrix)
{
	out(in.x * matrix.m[0][0] + in.y * matrix.m[1][0] + in.z * matrix.m[2][0] + matrix.m[3][0],
		in.x * matrix.m[0][1] + in.y * matrix.m[1][1] + in.z * matrix.m[2][1] + matrix.m[3][1],
		in.x * matrix.m[0][2] + in.y * matrix.m[1][2] + in.z * matrix.m[2][2] + matrix.m[3][2]);
}

//--------------------------------------------------------------------------------------------------
//Description: 3D座標をスクリーン座標に変換する関数( ワールド変換無し )
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matView:ビュー変換行列, matProj:射影変換行列, matViewport:ビューポート変換行列
void Math::GetVector3TransformToScreen(Math::Vector3& out, const Math::Vector3& in, const Math::Matrix& matView, const Math::Matrix& matProj, const Math::Matrix& matViewport)
{
	Math::Vector4 vec(in.x, in.y, in.z, 1.0f);
	Math::GetVector4TransformMatrix(vec, vec, matView);
	Math::GetVector4TransformMatrix(vec, vec, matProj);
	if (vec.z <= 0.0f) return;
	vec.x /= vec.w;
	vec.y /= vec.w;
	vec.z /= vec.w;
	vec.w = 1.0f;
	Math::GetVector3TransformMatrix(out, Math::ToVector3(vec), matViewport);
}

//--------------------------------------------------------------------------------------------------
//Description: 3D座標をスクリーン座標に変換する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matTransform:変換行列
void Math::GetVector3TransformToScreen(Vector3& out, const Vector3& in, const Matrix& matWorld, const Matrix& matView, const Matrix& matProj, const Matrix& matViewport)
{
	Math::Vector4 vec(in.x, in.y, in.z, 1.0f);
	Math::GetVector4TransformMatrix(vec, vec, matWorld);
	Math::GetVector4TransformMatrix(vec, vec, matView);
	Math::GetVector4TransformMatrix(vec, vec, matProj);
	if (vec.z <= 0.0f) return;
	vec.x /= vec.w;
	vec.y /= vec.w;
	vec.z /= vec.w;
	vec.w = 1.0f;
	Math::GetVector3TransformMatrix(out, Math::ToVector3(vec), matViewport);
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       left:左辺値, right:右辺値
Math::Vector3 Math::operator *(float left, const Math::Vector3& right)
{
	return Math::Vector3(left * right.x, left * right.y, left * right.z);
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       left:左辺値, right:右辺値
Math::Vector3 Math::operator *(const Math::Vector3& left, float right)
{
	return Math::Vector3(left.x * right, left.y * right, left.z * right);
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       left:左辺値, right:右辺値
Math::Vector3& Math::operator *=(Math::Vector3& left, float right)
{
	return left(left.x * right, left.y * right, left.z * right);
}

//--------------------------------------------------------------------------------------------------
//Description: ベクトルを行列で変換する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matrix:行列
void Math::GetVector4TransformMatrix(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matrix)
{
	out(in.x * matrix.m[0][0] + in.y * matrix.m[1][0] + in.z * matrix.m[2][0] + in.w * matrix.m[3][0],
		in.x * matrix.m[0][1] + in.y * matrix.m[1][1] + in.z * matrix.m[2][1] + in.w * matrix.m[3][1],
		in.x * matrix.m[0][2] + in.y * matrix.m[1][2] + in.z * matrix.m[2][2] + in.w * matrix.m[3][2],
		in.x * matrix.m[0][3] + in.y * matrix.m[1][3] + in.z * matrix.m[2][3] + in.w * matrix.m[3][3]);
}

//--------------------------------------------------------------------------------------------------
//Description: 3D座標をスクリーン座標変換する関数( ワールド変換無し )
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matView:ビュー変換行列, matProj:射影変換行列, matViewport:ビューポート行列 
void Math::GetVector4TransformToScreen(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matView, const Math::Matrix& matProj, const Math::Matrix& matViewport)
{
	Math::GetVector4TransformMatrix(out, in, matView);
	Math::GetVector4TransformMatrix(out, out, matProj);
	if (out.z <= 0.0f) return;
	out.x /= out.w;
	out.y /= out.w;
	out.z /= out.w;
	out.w = 1.0f;
	Math::GetVector4TransformMatrix(out, out, matViewport);
}

//--------------------------------------------------------------------------------------------------
//Description: 3D座標をスクリーン座標変換する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:対象, matWorld:ワールド変換行列, matView:ビュー変換行列, matProj:射影変換行列, matViewport:ビューポート行列
void Math::GetVector4TransformToScreen(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matWorld, const Math::Matrix& matView, const Math::Matrix& matProj, const Matrix& matViewport)
{
	//ワールド変換
	Math::GetVector4TransformMatrix(out, in, matWorld);

	//ビュー変換
	Math::GetVector4TransformMatrix(out, out, matView);

	//プロジェクション変換
	Math::GetVector4TransformMatrix(out, out, matProj);
	if (out.z <= 0) return;
	out.x /= out.w;
	out.y /= out.w;
	out.z /= out.w;
	out.w = 1.0f;

	//ビューポート変換
	Math::GetVector4TransformMatrix(out, out, matViewport);
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       left:左辺値, right:右辺値
Math::Vector4 Math::operator *(float left, const Math::Vector4& right)
{
	return Math::Vector4(left * right.x, left * right.y, left * right.z, left * right.w);
}

//--------------------------------------------------------------------------------------------------
//Description: 乗算演算子
//Return:      計算結果
//Param:       left:左辺値, right:右辺値
Math::Vector4 Math::operator *(const Math::Vector4& left, float right)
{
	return Math::Vector4(left.x * right, left.y * right, left.z * right, left.w * right);
}

//--------------------------------------------------------------------------------------------------
//Description: 単位クォータニオンを取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される
void Math::GetQuaternionIdentity(Math::Quaternion& out)
{
	out.w = 1.0f;
	out.x = out.y = out.z = 0.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 逆クォータニオンを取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される
void Math::GetQuaternionInverse(Math::Quaternion& out, const Math::Quaternion& in)
{
	const float length2 = in.Length2();

	//長さが0なら処理を終了する
	if (length2 == 0) return;
	out.x = -in.x / length2;
	out.y = -in.y / length2;
	out.z = -in.z / length2;
	out.w = in.w / length2;
}

//--------------------------------------------------------------------------------------------------
//Description: 回転クォータニオンを取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される, axis:回転軸, radian:回転角度
void Math::GetQuaternionRotation(Math::Quaternion& out, const Math::Vector3& axis, float radian)
{
	//軸ベクトルが単位ベクトルでなければ単位ベクトルに変換する
	Math::Vector3 norm = axis;
	if (axis.Length2() != 1.0f) {
		Math::Normalize(norm);
	}

	float sin_t2 = sin(0.5f * radian);
	float cos_t2 = cos(0.5f * radian);

	out.w = cos_t2;
	out.x = norm.x * sin_t2;
	out.y = norm.y * sin_t2;
	out.z = norm.z * sin_t2;
}

//--------------------------------------------------------------------------------------------------
//Description: 球面線形補間する関数
//Return:      無し
//Param:       out:ここに結果が代入される, start:補間開始地点, end:補間終了地点, t:補間係数( 0~1 )
void Math::GetQuaternionSlerp(Quaternion& out, const Quaternion& start, const Quaternion& end, float t)
{
	Quaternion left(start), right(end);
	Math::Normalize(left);
	Math::Normalize(right);
	const float len1 = left.Length();
	const float len2 = right.Length();

	if (len1 == 0.0f || len2 == 0.0f)
		return;

	const float cos_val = left.Dot(right) / (len1 * len2);
	if (cos_val >= 1.0f) {
		out = start;
		return;
	}
	const float w = acosf(cos_val);

	const float sin_w = sinf(w);
	const float sin_t_w = sinf(t * w);
	const float sin_inv_t_w = sinf((1.0f - t) * w);
	const float mult_q1 = sin_inv_t_w / sin_w;
	const float mult_q2 = sin_t_w / sin_w;

	out.x = mult_q1 * left.x + mult_q2 * right.x;
	out.y = mult_q1 * left.y + mult_q2 * right.y;
	out.z = mult_q1 * left.z + mult_q2 * right.z;
	out.w = mult_q1 * left.w + mult_q2 * right.w;
}

//--------------------------------------------------------------------------------------------------
//Description: 回転行列へ変換する関数
//Return:      無し
//Param:       out:ここに結果が代入される, in:回転クォータニオン
void Math::GetMatrixFromQuaternion(Math::Matrix& out, const Math::Quaternion& in)
{
	out.m[0][0] = 1.0f - 2.0f * in.y * in.y - 2.0f * in.z * in.z;
	out.m[0][1] = 2.0f * in.x * in.y + 2.0f * in.w * in.z;
	out.m[0][2] = 2.0f * in.x * in.z - 2.0f * in.w * in.y;
	out.m[0][3] = 0.0f;

	out.m[1][0] = 2.0f * in.x * in.y - 2.0f * in.w * in.z;
	out.m[1][1] = 1.0f - 2.0f * in.x * in.x - 2.0f * in.z * in.z;
	out.m[1][2] = 2.0f * in.y * in.z + 2.0f * in.w * in.x;
	out.m[1][3] = 0.0f;

	out.m[2][0] = 2.0f * in.x * in.z + 2.0f * in.w * in.y;
	out.m[2][1] = 2.0f * in.y * in.z - 2.0f * in.w * in.x;
	out.m[2][2] = 1.0f - 2.0f * in.x * in.x - 2.0f * in.y * in.y;
	out.m[2][3] = 0.0f;

	out.m[3][0] = 0.0f;
	out.m[3][1] = 0.0f;
	out.m[3][2] = 0.0f;
	out.m[3][3] = 1.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 単為行列を取得する関数
//Return:      無し
//Param:       out:ここに結果が代入される
void Math::GetMatrixIdentity(Math::Matrix& out)
{
	out.row[0](1.0f, 0.0f, 0.0f, 0.0f);
	out.row[1](0.0f, 1.0f, 0.0f, 0.0f);
	out.row[2](0.0f, 0.0f, 1.0f, 0.0f);
	out.row[3](0.0f, 0.0f, 0.0f, 1.0f);
}

//--------------------------------------------------------------------------------------------------
//Description: 逆行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, in:対象
void Math::GetMatrixInverse(Math::Matrix& out, const Math::Matrix& in)
{
	Math::Matrix mat = in;
	float buf;

	//掃き出し法
	for (int i = 0; i < 4; i++)
	{
		buf = 1.0f / mat.m[i][i];
		for (int j = 0; j < 4; j++)
		{
			mat.m[i][j] *= buf;
			out.m[i][j] *= buf;
		}
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				buf = mat.m[j][i];
				for (int k = 0; k < 4; k++)
				{
					mat.m[j][k] -= mat.m[i][k] * buf;
					out.m[j][k] -= out.m[i][k] * buf;
				}
			}
		}
	}
}

//--------------------------------------------------------------------------------------------------
//Description: 転置行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, in:対象
void Math::GetMatrixTranspose(Math::Matrix& out, const Math::Matrix& in)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			out.m[i][j] = in.m[j][i];
		}
	}
}

//--------------------------------------------------------------------------------------------------
//Description: x軸回転する回転行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, radian:回転角度
void Math::GetMatrixRotationX(Math::Matrix& out, float radian)
{
	const float sin_t = sin(radian), cos_t = cos(radian);
	out.m[0][0] = 1.0f;
	out.m[0][1] = 0.0f;
	out.m[0][2] = 0.0f;
	out.m[0][3] = 0.0f;

	out.m[1][0] = 0.0f;
	out.m[1][1] = cos_t;
	out.m[1][2] = sin_t;
	out.m[1][3] = 0.0f;

	out.m[2][0] = 0.0f;
	out.m[2][1] = -sin_t;
	out.m[2][2] = cos_t;
	out.m[2][3] = 0.0f;

	out.m[3][0] = 0.0f;
	out.m[3][1] = 0.0f;
	out.m[3][2] = 0.0f;
	out.m[3][3] = 1.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: y軸回転する回転行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, radian:回転角度
void Math::GetMatrixRotationY(Matrix& out, const float radian)
{
	const float sin_t = sin(radian), cos_t = cos(radian);
	out.m[0][0] = cos_t;
	out.m[0][1] = 0.0f;
	out.m[0][2] = -sin_t;
	out.m[0][3] = 0.0f;

	out.m[1][0] = 0.0f;
	out.m[1][1] = 1.0f;
	out.m[1][2] = 0.0f;
	out.m[1][3] = 0.0f;

	out.m[2][0] = sin_t;
	out.m[2][1] = 0.0f;
	out.m[2][2] = cos_t;
	out.m[2][3] = 0.0f;

	out.m[3][0] = 0.0f;
	out.m[3][1] = 0.0f;
	out.m[3][2] = 0.0f;
	out.m[3][3] = 1.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: z軸回転する回転行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, radian:回転角度
void Math::GetMatrixRotationZ(Math::Matrix& out, float radian)
{
	const float sin_t = sin(radian), cos_t = cos(radian);
	out.m[0][0] = cos_t;
	out.m[0][1] = sin_t;
	out.m[0][2] = 0.0f;
	out.m[0][3] = 0.0f;

	out.m[1][0] = -sin_t;
	out.m[1][1] = cos_t;
	out.m[1][2] = 0.0f;
	out.m[1][3] = 0.0f;

	out.m[2][0] = 0.0f;
	out.m[2][1] = 0.0f;
	out.m[2][2] = 1.0f;
	out.m[2][3] = 0.0f;

	out.m[3][0] = 0.0f;
	out.m[3][1] = 0.0f;
	out.m[3][2] = 0.0f;
	out.m[3][3] = 1.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 任意軸回転する回転行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, axis:軸ベクトル(単位ベクトル), radian:回転角度
void Math::GetMatrixRotationAxis(Math::Matrix& out, const Math::Vector3& axis, float radian)
{
	const float sin_t = sin(radian), cos_t = cos(radian);
	out.m[0][0] = axis.x * axis.x * (1.0f - cos_t) + cos_t;
	out.m[0][1] = axis.x * axis.y * (1.0f - cos_t) + axis.z * sin_t;
	out.m[0][2] = axis.x * axis.z * (1.0f - cos_t) - axis.y * sin_t;
	out.m[0][3] = 0.0f;

	out.m[1][0] = axis.x * axis.y * (1.0f - cos_t) - axis.z * sin_t;
	out.m[1][1] = axis.y * axis.y * (1.0f - cos_t) + cos_t;
	out.m[1][2] = axis.y * axis.z * (1.0f - cos_t) + axis.x * sin_t;
	out.m[1][3] = 0.0f;

	out.m[2][0] = axis.x * axis.z * (1.0f - cos_t) + axis.y * sin_t;
	out.m[2][1] = axis.y * axis.z * (1.0f - cos_t) - axis.x * sin_t;
	out.m[2][2] = axis.z * axis.z * (1.0f - cos_t) + cos_t;
	out.m[2][3] = 0.0f;

	out.m[3][0] = 0.0f;
	out.m[3][1] = 0.0f;
	out.m[3][2] = 0.0f;
	out.m[3][3] = 1.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 拡縮行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, scale:各要素の拡大倍率
void Math::GetMatrixScale(Math::Matrix& out, const Math::Vector3& scale)
{
	out.m[0][0] = scale.x;
	out.m[0][1] = out.m[0][2] = out.m[0][3] = 0.0f;

	out.m[1][1] = scale.y;
	out.m[1][0] = out.m[1][2] = out.m[1][3] = 0.0f;

	out.m[2][2] = scale.z;
	out.m[2][0] = out.m[2][1] = out.m[2][3] = 0.0f;

	out.m[3][3] = 1.0f;
	out.m[3][0] = out.m[3][1] = out.m[3][2] = 0.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 平行移動行列を取得する関数
//Return:      無し
//Param:       out:結果が出力される, position:移動する位置
void Math::GetMatrixTranslation(Math::Matrix& out, const Math::Vector3& position)
{
	out.m[0][0] = 1.0f;
	out.m[0][1] = out.m[0][2] = out.m[0][3] = 0.0f;

	out.m[1][1] = 1.0f;
	out.m[1][0] = out.m[1][2] = out.m[1][3] = 0.0f;

	out.m[2][2] = 1.0f;
	out.m[2][0] = out.m[2][1] = out.m[2][3] = 0.0f;

	out.m[3][0] = position.x;
	out.m[3][1] = position.y;
	out.m[3][2] = position.z;
	out.m[3][3] = 1.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: 回転行列からクォータニオンを取得する関数
//Return:      無し
//Param:       out:結果が出力される, in:対象
void Math::GetQuaternionFromMatrix(Math::Quaternion& out, const Math::Matrix& in)
{
	//最大成分を検索
	float elem[4];
	elem[0] = in.m[0][0] - in.m[1][1] - in.m[2][2] + 1.0f;
	elem[1] = -in.m[0][0] + in.m[1][1] - in.m[2][2] + 1.0f;
	elem[2] = -in.m[0][0] - in.m[1][1] + in.m[2][2] + 1.0f;
	elem[3] = in.m[0][0] + in.m[1][1] + in.m[2][2] + 1.0f;

	unsigned biggestIndex = 0;
	for (int i = 1; i < 4; i++)
	{
		if (elem[i] > elem[biggestIndex])
			biggestIndex = i;
	}

	if (elem[biggestIndex] < 0.0f)
		return;

	//最大要素の算出
	float* q[4] = { &out.x, &out.y, &out.z, &out.w };
	float v = sqrtf(elem[biggestIndex]) * 0.5f;
	*q[biggestIndex] = v;
	float mult = 0.25f / v;

	switch (biggestIndex)
	{
	case 0:
		*q[1] = (in.m[0][1] + in.m[1][0]) * mult;
		*q[2] = (in.m[2][0] + in.m[0][2]) * mult;
		*q[3] = (in.m[1][2] - in.m[2][1]) * mult;
		break;
	case 1:
		*q[0] = (in.m[0][1] + in.m[1][0]) * mult;
		*q[2] = (in.m[1][2] + in.m[2][1]) * mult;
		*q[3] = (in.m[2][0] - in.m[0][2]) * mult;
		break;
	case 2:
		*q[0] = (in.m[2][0] + in.m[0][2]) * mult;
		*q[1] = (in.m[1][2] + in.m[2][1]) * mult;
		*q[3] = (in.m[0][1] - in.m[1][0]) * mult;
		break;
	case 3:
		*q[0] = (in.m[1][2] - in.m[2][1]) * mult;
		*q[1] = (in.m[2][0] - in.m[0][2]) * mult;
		*q[2] = (in.m[0][1] - in.m[1][0]) * mult;
		break;
	}
}
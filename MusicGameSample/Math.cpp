#include <math.h>
#include "Math.h"

//static�t�B�[���h�̏�����
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
//Description: �֐��Ăяo�����Z�q
//Return:      �Q��
//Param:       x, y:�v�f
const Math::Vector2& Math::Vector2::operator ()(const float x, const float y)
{
	this->x = x;
	this->y = y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ������Z�q
//Return:      ���Z����
//Param:       right:�E�Ӓl
const Math::Vector2& Math::Vector2::operator= (const Math::Vector2& right)
{
	//���ȑ���`�F�b�N
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
//Description: �}�C�i�X�������Z�q
//Return:      �v�Z����
//Param:       ����
Math::Vector2 Math::Vector2::operator -() const
{
	return Vector2(-x, -y);
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���ς��擾����֐�
//Return:      ����
//Param:       right:�E�Ӓl
float Math::Vector2::Dot(const Math::Vector2& right) const
{
	return x * right.x + y * right.y;
}

//--------------------------------------------------------------------------------------------------
//Description: �O�ς��擾����֐�
//Return:      �O��(�萔)
//Param:       right:�E�Ӓl
float Math::Vector2::Cross(const Math::Vector2& right) const
{
	const float src_len = this->Length();
	const float trg_len = right.Length();
	const float angle = acosf(this->Dot(right) / (src_len * trg_len));

	return src_len * trg_len * sinf(angle);
}

//--------------------------------------------------------------------------------------------------
//Description: �������擾����֐�
//Return:      �x�N�g���̒���
//Param:       ����
float Math::Vector2::Length(void) const
{
	return sqrt(Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: ������2����擾����֐�
//Return:      �x�N�g���̒�����2��
//Param:       ����
float Math::Vector2::Length2(void) const
{
	return x * x + y * y;
}

//--------------------------------------------------------------------------------------------------
//Description: �Ȃ��p���擾����֐�
//Return:      �p�x
//Param:       right:�E�Ӓl
float Math::Vector2::Angle(const Math::Vector2& right) const
{
	const float cos_val = Dot(right) / (Length() * right.Length());
	return acosf(cos_val);
}

//--------------------------------------------------------------------------------------------------
//Description: �Ȃ��p���擾����֐�( -�΁`�� )
//Return:      �p�x( ���W�A�� )
//Param:       right:�E�Ӓl
float Math::Vector2::Angle2(const Math::Vector2& right) const
{
	const float cross = this->Cross(right);

	//�O�ϒl��0�ȉ��Ȃ玞�v������
	if (cross < 0)
	{
		return Angle(right);
	}
	//0�ȏ�Ȃ甽���v������
	else if (cross > 0)
	{
		return -Angle(right);
	}

	//���������Ȃ��0��Ԃ�
	return 0.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: �������擾����֐�
//Return:      ����
//Param:       target:�Ώ�
float Math::Vector2::Distance(const Math::Vector2& target) const
{
	return sqrt(this->Distance2(target));
}

//--------------------------------------------------------------------------------------------------
//Description: ������2����擾����֐�
//Return:      ����
//Param:       target:�Ώ�
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
//Description: �}�C�i�X�������Z�q
//Return:      �v�Z����
//Param:       ����
Math::Vector3 Math::Vector3::operator -(void) const
{
	return Math::Vector3(-x, -y, -z);
}

//--------------------------------------------------------------------------------------------------
//Description: �֐��Ăяo�����Z�q
//Return:      ���g�̎Q��
//Param:       x, y:�v�f
Math::Vector3& Math::Vector3::operator ()(float x, float y)
{
	this->x = x;
	this->y = y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: �֐��Ăяo�����Z�q
//Return:      ���g�̎Q��
//Param:       x, y, z:�v�f
Math::Vector3& Math::Vector3::operator ()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ������Z�q
//Return:      ���g�̎Q��
//Param:       right:�E�Ӓl
const Math::Vector3& Math::Vector3::operator =(const Math::Vector2& right)
{
	//���ȑ���`�F�b�N
	this->x = right.x;
	this->y = right.y;

	return *this;
}
const Math::Vector3& Math::Vector3::operator =(const Math::Vector3& right)
{
	//���ȑ���`�F�b�N
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
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: �������擾����֐�
//Return:      �x�N�g���̒���
//Param:       ����
float Math::Vector3::Length() const
{
	return sqrt(Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: ������2����擾����֐�
//Return:      �x�N�g���̒�����2��
//Param:       ����
float Math::Vector3::Length2() const
{
	return x * x + y * y + z * z;
}

//--------------------------------------------------------------------------------------------------
//Description: 2�_�Ԃ̋������擾����֐�
//Return:      ����
//Param:       to:�Ώۂ̈ʒu�x�N�g��
float Math::Vector3::Distance(const Math::Vector3& to) const
{
	return sqrt((to.x - x) * (to.x - x) + (to.y - y) * (to.y - y) + (to.z - z) * (to.z - z));
}

//--------------------------------------------------------------------------------------------------
//Description: �Ȃ��p���擾����֐�
//Return:      �p�x
//Param:       right:�E�Ӓl
float Math::Vector3::Angle(const Math::Vector3& right) const
{
	const float cos_val = Dot(right) / (Length() * right.Length());
	return acosf(cos_val);
}

//--------------------------------------------------------------------------------------------------
//Description: ���ς��擾����֐�
//Return:      ����
//Param:       right:�E�Ӓl
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
//Description: �֐��Ăяo�����Z�q
//Return:      ���g�̎Q��
//Param:       x, y:�v�f
const Math::Vector4& Math::Vector4::operator ()(float x, float y)
{
	this->x = x;
	this->y = y;

	return *this;
}
//--------------------------------------------------------------------------------------------------
//Description: �֐��Ăяo�����Z�q
//Return:      ���g�̎Q��
//Param:       x, y, z:�v�f
const Math::Vector4& Math::Vector4::operator ()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: �֐��Ăяo�����Z�q
//Return:      ���g�̎Q��
//Param:       x, y, z, w:�v�f
const Math::Vector4& Math::Vector4::operator ()(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ������Z�q
//Return:      ���g�̎Q��
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator =(const Math::Vector2& right)
{
	//���ȑ���`�F�b�N
	this->x = right.x;
	this->y = right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ������Z�q
//Return:      ���g�̎Q��
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator =(const Math::Vector3& right)
{
	//���ȑ���`�F�b�N
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ������Z�q
//Return:      ���g�̎Q��
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator =(const Math::Vector4& right)
{
	//���ȑ���`�F�b�N
	if (this == &right) return *this;
	this->x = right.x;
	this->y = right.y;
	this->z = right.z;
	this->w = right.w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator +=(const Vector2& right)
{
	this->x += right.x;
	this->y += right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator +=(const Vector3& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator +=(const Vector4& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	this->w += right.w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator -=(const Math::Vector2& right)
{
	this->x -= right.x;
	this->y -= right.y;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator -=(const Math::Vector3& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Vector4& Math::Vector4::operator -=(const Vector4& right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	this->w -= right.w;

	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Vector4 Math::Vector4::operator +(const Math::Vector2& right) const
{
	Math::Vector4 ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Vector4 Math::Vector4::operator +(const Math::Vector3& right) const
{
	Math::Vector4 ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Vector4 Math::Vector4::operator +(const Math::Vector4& right) const
{
	Math::Vector4 ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Vector4 Math::Vector4::operator -(const Math::Vector2& right) const
{
	Math::Vector4 ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Vector4 Math::Vector4::operator -(const Math::Vector3& right) const
{
	Math::Vector4 ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Vector4 Math::Vector4::operator -(const Math::Vector4& right) const
{
	Math::Vector4 ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: �x�N�g���̐�Βl���擾����֐�
//Return:      �x�N�g���̐�Βl
//Param:       ����
float Math::Vector4::Length(void) const
{
	return sqrt(this->Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: �x�N�g���̐�Βl���擾����֐�
//Return:      �x�N�g���̐�Βl
//Param:       ����
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
//Description: �֐��Ăяo�����Z�q
//Return:      ���Z����
//Param:       x, y:�i�[����l
const Math::Quaternion& Math::Quaternion::operator()(float x, float y)
{
	this->x = x;
	this->y = y;
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: �֐��Ăяo�����Z�q
//Return:      ���Z����
//Param:       x, y, z:�i�[����l
const Math::Quaternion& Math::Quaternion::operator()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: �֐��Ăяo�����Z�q
//Return:      ���Z����
//Param:       x, y, z, w:�i�[����l
const Math::Quaternion& Math::Quaternion::operator()(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
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
//Description: ��Z������Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
const Math::Quaternion& Math::Quaternion::operator *=(const Math::Quaternion& right)
{
	(*this)(right.y * z - right.z * y + right.w * x + w * right.x,		// v1�~v2 + w1*v2 + w2*v1
		right.z * x - right.x * z + right.w * y + w * right.y,
		right.x * y - right.y * x + right.w * z + w * right.z,
		w * right.w - x * right.x + y * right.y + z * right.z);	// w1*w2 - (v1�Ev2)
	return *this;
}

//--------------------------------------------------------------------------------------------------
//Description: ���ς����߂�֐�
//Return:      ����
//Param:       right:�E�Ӓl
float Math::Quaternion::Dot(const Math::Quaternion& right) const
{
	return x * right.x + y * right.y + z * right.z * w + right.w;
}


//--------------------------------------------------------------------------------------------------
//Description: �������擾����֐�
//Return:      �N�H�[�^�j�I���̒���
//Param:       ����
float Math::Quaternion::Length(void) const
{
	return sqrt(this->Length2());
}

//--------------------------------------------------------------------------------------------------
//Description: �����̂Q����擾����֐�
//Return:      �N�H�[�^�j�I���̒����̂Q��
//Param:       ����
float Math::Quaternion::Length2(void) const
{
	return x * x + y * y + z * z + w * w;
}

//--------------------------------------------------------------------------------------------------
//Description: �R���X�g���N�^
//Return:      ����
//Param:       _~~:�ԍ��ɑΉ������v�f
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
//Description: �R���X�g���N�^
//Return:      ����
//Param:       _~~:�ԍ��ɑΉ������v�f
Math::Matrix::Matrix(const Matrix& right)
{
	row[0] = right.row[0];
	row[1] = right.row[1];
	row[2] = right.row[2];
	row[3] = right.row[3];
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Matrix Math::Matrix::operator +(const Math::Matrix& right) const
{
	Math::Matrix ret = *this;
	return ret += right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Matrix Math::Matrix::operator -(const Math::Matrix& right) const
{
	Math::Matrix ret = *this;
	return ret -= right;
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       right:�E�Ӓl
Math::Matrix Math::Matrix::operator *(const Math::Matrix& right) const
{
	Math::Matrix ret = *this;
	return ret *= right;
}

//--------------------------------------------------------------------------------------------------
//Description: ���Z������Z�q
//Return:      ����
//Param:       right:�E�Ӓl
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
//Description: ���Z������Z�q
//Return:      ����
//Param:       right:�E�Ӓl
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
//Description: ��Z������Z�q
//Return:      ����
//Param:       right:�E�Ӓl
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
//Description: �P�ʃx�N�g�����擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�
void Math::Normalize(Math::Vector2& target)
{
	const float length = target.Length();

	//������0�Ȃ�ΐ��K���̕K�v�Ȃ�
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: �P�ʃx�N�g�����擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�
void Math::Normalize(Math::Vector3& target)
{
	const float length = target.Length();

	//������0�Ȃ�ΐ��K���̕K�v�Ȃ�
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
	target.z /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: �P�ʃx�N�g�����擾����֐�
//Return:      ����
//Param:       target:�Ώ�
void Math::Normalize(Math::Vector4& target)
{
	const float length = target.Length();

	//������0�̏ꍇ�͐��K���ł��Ȃ�
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
	target.z /= length;
	target.w /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: ���K������֐�
//Return:      ����
//Param:       target:�Ώ�
void Math::Normalize(Math::Quaternion& target)
{
	const float length = target.Length();

	//������0�Ȃ�ΐ��K���̕K�v�Ȃ�
	if (length == 0) return;
	target.x /= length;
	target.y /= length;
	target.z /= length;
	target.w /= length;
}

//--------------------------------------------------------------------------------------------------
//Description: �x�N�g������]������֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, radian:��]�p
void Math::GetVector2Rotation(Math::Vector2& out, const Math::Vector2& in, float radian)
{
	const float sin_val = sin(radian);
	const float cos_val = cos(radian);
	out.x = cos_val - sin_val;
	out.y = sin_val + cos_val;
}

//--------------------------------------------------------------------------------------------------
//Description: �x�N�g�����s��ŕϊ�����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matrix:�s��
void Math::GetVector2TransformMatrix(Math::Vector2& out, const Math::Vector3& in, const Math::Matrix& matrix)
{
	out(in.x * matrix.m[0][0] + in.y * matrix.m[1][0] + in.z * matrix.m[2][0] + matrix.m[3][0],
		in.x * matrix.m[0][1] + in.y * matrix.m[1][1] + in.z * matrix.m[2][1] + matrix.m[3][1]);
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       out:�����Ɍ��ʂ��o�͂����, left:���Ӓl, right:�E�Ӓl
Math::Vector2 Math::operator *(float left, const Math::Vector2& right)
{
	return Math::Vector2(left * right.x, left * right.y);
}
Math::Vector2 Math::operator *(const Math::Vector2& left, float right)
{
	return Math::Vector2(left.x * right, left.y * right);
}



//--------------------------------------------------------------------------------------------------
//Description: �O�ς��擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, left:���Ӓl, right:�E�Ӓl
void Math::GetVector3Cross(Math::Vector3& out, const Math::Vector3& left, const Math::Vector3& right)
{
	out(left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
}

//--------------------------------------------------------------------------------------------------
//Description: x����]������֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, radian:��]�p�x
void Math::GetVector3RotationX(Math::Vector3& out, const Math::Vector3& in, float radian)
{
	Math::Vector3 XAxis(1.0f, 0.0f, 0.0f);
	Math::GetVector3RotationAxis(out, in, XAxis, radian);
}

//--------------------------------------------------------------------------------------------------
//Description: y����]������֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, radian:��]�p�x
void Math::GetVector3RotationY(Math::Vector3& out, const Math::Vector3& in, float radian)
{
	Math::Vector3 YAxis(0.0f, 1.0f, 0.0f);
	Math::GetVector3RotationAxis(out, in, YAxis, radian);
}

//--------------------------------------------------------------------------------------------------
//Description: z����]������֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, radian:��]�p�x
void Math::GetVector3RotationZ(Math::Vector3& out, const Math::Vector3& in, float radian)
{
	Math::Vector3 ZAxis(0.0f, 0.0f, 1.0f);
	Math::GetVector3RotationAxis(out, in, ZAxis, radian);
}

//--------------------------------------------------------------------------------------------------
//Description: �C�ӎ���]������֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, axis:��]��, radian:��]�p�x
void Math::GetVector3RotationAxis(Math::Vector3& out, const Math::Vector3& in, const Math::Vector3& axis, float radian)
{
	Math::Quaternion quat;
	Math::GetQuaternionRotation(quat, axis, radian);
	Math::GetVector3RotationQuaternion(out, in, quat);
}

//--------------------------------------------------------------------------------------------------
//Description: �N�H�[�^�j�I���ŉ�]������֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, quat:��]�N�H�[�^�j�I��
void Math::GetVector3RotationQuaternion(Math::Vector3& out, const Math::Vector3& in, const Math::Quaternion& quat)
{
	//P' = Q * P * R;( R��Q�̋����l���� )
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
//Description: ���ʐ��`��Ԃ���֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, start:��ԊJ�n�n�_, end:��ԏI���n�_, t:��ԌW��( 0~1 )
void Math::GetVector3Slerp(Math::Vector3& out, const Math::Vector3& start, const Math::Vector3& end, float t)
{
	Math::Quaternion s(start), e(end);
	Math::GetQuaternionSlerp(s, s, e, t);
	out(s.x, s.y, s.z);
}

//--------------------------------------------------------------------------------------------------
//Description: �x�N�g�����s��ŕϊ�����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matrix:�s��
void Math::GetVector3TransformMatrix(Math::Vector3& out, const Math::Vector3& in, const Math::Matrix& matrix)
{
	out(in.x * matrix.m[0][0] + in.y * matrix.m[1][0] + in.z * matrix.m[2][0] + matrix.m[3][0],
		in.x * matrix.m[0][1] + in.y * matrix.m[1][1] + in.z * matrix.m[2][1] + matrix.m[3][1],
		in.x * matrix.m[0][2] + in.y * matrix.m[1][2] + in.z * matrix.m[2][2] + matrix.m[3][2]);
}

//--------------------------------------------------------------------------------------------------
//Description: 3D���W���X�N���[�����W�ɕϊ�����֐�( ���[���h�ϊ����� )
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matView:�r���[�ϊ��s��, matProj:�ˉe�ϊ��s��, matViewport:�r���[�|�[�g�ϊ��s��
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
//Description: 3D���W���X�N���[�����W�ɕϊ�����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matTransform:�ϊ��s��
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
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       left:���Ӓl, right:�E�Ӓl
Math::Vector3 Math::operator *(float left, const Math::Vector3& right)
{
	return Math::Vector3(left * right.x, left * right.y, left * right.z);
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       left:���Ӓl, right:�E�Ӓl
Math::Vector3 Math::operator *(const Math::Vector3& left, float right)
{
	return Math::Vector3(left.x * right, left.y * right, left.z * right);
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       left:���Ӓl, right:�E�Ӓl
Math::Vector3& Math::operator *=(Math::Vector3& left, float right)
{
	return left(left.x * right, left.y * right, left.z * right);
}

//--------------------------------------------------------------------------------------------------
//Description: �x�N�g�����s��ŕϊ�����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matrix:�s��
void Math::GetVector4TransformMatrix(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matrix)
{
	out(in.x * matrix.m[0][0] + in.y * matrix.m[1][0] + in.z * matrix.m[2][0] + in.w * matrix.m[3][0],
		in.x * matrix.m[0][1] + in.y * matrix.m[1][1] + in.z * matrix.m[2][1] + in.w * matrix.m[3][1],
		in.x * matrix.m[0][2] + in.y * matrix.m[1][2] + in.z * matrix.m[2][2] + in.w * matrix.m[3][2],
		in.x * matrix.m[0][3] + in.y * matrix.m[1][3] + in.z * matrix.m[2][3] + in.w * matrix.m[3][3]);
}

//--------------------------------------------------------------------------------------------------
//Description: 3D���W���X�N���[�����W�ϊ�����֐�( ���[���h�ϊ����� )
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matView:�r���[�ϊ��s��, matProj:�ˉe�ϊ��s��, matViewport:�r���[�|�[�g�s�� 
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
//Description: 3D���W���X�N���[�����W�ϊ�����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:�Ώ�, matWorld:���[���h�ϊ��s��, matView:�r���[�ϊ��s��, matProj:�ˉe�ϊ��s��, matViewport:�r���[�|�[�g�s��
void Math::GetVector4TransformToScreen(Math::Vector4& out, const Math::Vector4& in, const Math::Matrix& matWorld, const Math::Matrix& matView, const Math::Matrix& matProj, const Matrix& matViewport)
{
	//���[���h�ϊ�
	Math::GetVector4TransformMatrix(out, in, matWorld);

	//�r���[�ϊ�
	Math::GetVector4TransformMatrix(out, out, matView);

	//�v���W�F�N�V�����ϊ�
	Math::GetVector4TransformMatrix(out, out, matProj);
	if (out.z <= 0) return;
	out.x /= out.w;
	out.y /= out.w;
	out.z /= out.w;
	out.w = 1.0f;

	//�r���[�|�[�g�ϊ�
	Math::GetVector4TransformMatrix(out, out, matViewport);
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       left:���Ӓl, right:�E�Ӓl
Math::Vector4 Math::operator *(float left, const Math::Vector4& right)
{
	return Math::Vector4(left * right.x, left * right.y, left * right.z, left * right.w);
}

//--------------------------------------------------------------------------------------------------
//Description: ��Z���Z�q
//Return:      �v�Z����
//Param:       left:���Ӓl, right:�E�Ӓl
Math::Vector4 Math::operator *(const Math::Vector4& left, float right)
{
	return Math::Vector4(left.x * right, left.y * right, left.z * right, left.w * right);
}

//--------------------------------------------------------------------------------------------------
//Description: �P�ʃN�H�[�^�j�I�����擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������
void Math::GetQuaternionIdentity(Math::Quaternion& out)
{
	out.w = 1.0f;
	out.x = out.y = out.z = 0.0f;
}

//--------------------------------------------------------------------------------------------------
//Description: �t�N�H�[�^�j�I�����擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������
void Math::GetQuaternionInverse(Math::Quaternion& out, const Math::Quaternion& in)
{
	const float length2 = in.Length2();

	//������0�Ȃ珈�����I������
	if (length2 == 0) return;
	out.x = -in.x / length2;
	out.y = -in.y / length2;
	out.z = -in.z / length2;
	out.w = in.w / length2;
}

//--------------------------------------------------------------------------------------------------
//Description: ��]�N�H�[�^�j�I�����擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, axis:��]��, radian:��]�p�x
void Math::GetQuaternionRotation(Math::Quaternion& out, const Math::Vector3& axis, float radian)
{
	//���x�N�g�����P�ʃx�N�g���łȂ���ΒP�ʃx�N�g���ɕϊ�����
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
//Description: ���ʐ��`��Ԃ���֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, start:��ԊJ�n�n�_, end:��ԏI���n�_, t:��ԌW��( 0~1 )
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
//Description: ��]�s��֕ϊ�����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������, in:��]�N�H�[�^�j�I��
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
//Description: �P�׍s����擾����֐�
//Return:      ����
//Param:       out:�����Ɍ��ʂ���������
void Math::GetMatrixIdentity(Math::Matrix& out)
{
	out.row[0](1.0f, 0.0f, 0.0f, 0.0f);
	out.row[1](0.0f, 1.0f, 0.0f, 0.0f);
	out.row[2](0.0f, 0.0f, 1.0f, 0.0f);
	out.row[3](0.0f, 0.0f, 0.0f, 1.0f);
}

//--------------------------------------------------------------------------------------------------
//Description: �t�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, in:�Ώ�
void Math::GetMatrixInverse(Math::Matrix& out, const Math::Matrix& in)
{
	Math::Matrix mat = in;
	float buf;

	//�|���o���@
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
//Description: �]�u�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, in:�Ώ�
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
//Description: x����]�����]�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, radian:��]�p�x
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
//Description: y����]�����]�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, radian:��]�p�x
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
//Description: z����]�����]�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, radian:��]�p�x
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
//Description: �C�ӎ���]�����]�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, axis:���x�N�g��(�P�ʃx�N�g��), radian:��]�p�x
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
//Description: �g�k�s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, scale:�e�v�f�̊g��{��
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
//Description: ���s�ړ��s����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, position:�ړ�����ʒu
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
//Description: ��]�s�񂩂�N�H�[�^�j�I�����擾����֐�
//Return:      ����
//Param:       out:���ʂ��o�͂����, in:�Ώ�
void Math::GetQuaternionFromMatrix(Math::Quaternion& out, const Math::Matrix& in)
{
	//�ő听��������
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

	//�ő�v�f�̎Z�o
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
#pragma once
#include "StrategyData.h"
#include "StrategyContext.h"
#include "StrategyInquiryDataInterface.h"
#include <map>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "boost/serialization/serialization.hpp"  
#include "boost/archive/binary_oarchive.hpp"  
#include "boost/archive/binary_iarchive.hpp"  
#include "boost/serialization/export.hpp"  
#include "boost/serialization/vector.hpp"  
#include "boost/serialization/deque.hpp" 
#include "boost/serialization/map.hpp" 
#include "boost/serialization/split_member.hpp"  
#include "boost/serialization/utility.hpp"
#include "boost/serialization/list.hpp"

#include <istream>
#include <ostream>
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace StrategyData;
using namespace std;
class MStrategyContext;
class MTick;
#ifdef WIN32

#ifdef EXPORT_STRATEGY 
#define STRATEGY_INTERFACE __declspec(dllexport) 
#else
#define STRATEGY_INTERFACE __declspec(dllimport) 
#endif

#else 

#define STRATEGY_INTERFACE

#endif



class STRATEGY_INTERFACE MStrategy
{
public:

	virtual TProbeStructType GetProbeStruct() = 0;								//��ȡ���Ի�ͼ̽��ṹ���׵�ַ

	virtual CParNode * GetParamStruct() = 0;									//��ȡ���Բ����ṹ���׵�ַ

	virtual bool OnInquiry(MStrategyInquiryDataInterface*) = 0;					//�����Զ��彻��

	virtual bool IsSupport(TStrategyTickType) = 0;								//�����Ƿ�֧�ָ������͵�tick

	virtual TLastErrorIdType OnInit(ptime CurrentTime) = 0;						//���Գ�ʼ��

	virtual TLastErrorIdType OnInit_FromArchive(ptime CurrentTime) = 0;			//�Ӵ浵�ļ�������OnInit

	virtual void OnTick(TMarketDataIdType, const CTick *) = 0;					//��������

	virtual void OnTrade(
		TOrderRefIdType,
		TOrderSysIdType,
		TVolumeType,
		TPriceType,
		TOrderDirectionType,
		TOrderOffsetType
		) = 0;																	//�����гɽ�

	virtual void OnOrder(
		TOrderRefIdType,
		TOrderSysIdType,
		TOrderDirectionType,
		TOrderStatusType,
		TPriceType,
		TTradedVolumeType,
		TRemainVolumeType
		) = 0;																	//����״̬�����仯

	virtual void OnEndup() = 0;													//ж�ز���ʱ����

	virtual void OnRelease() = 0;												//�ͷŲ���

	virtual void OnSave(const char * ) = 0;										//�������

	virtual void OnLoad(const char * ) = 0;										//���ز���
	
	virtual bool OnGetPositionInfo(int *) = 0;									//��ȡ���Ե�ǰ�ֲ֣�������Բ�֧�ִ˹��ܣ�����false����

	virtual bool OnGetCustomInfo(char *, size_t) = 0;							//��ȡ�û��Զ�����Ϣ��������Բ�֧�ִ˹��ܣ�����false����

	virtual bool OnGetFloatingProfit(double *) = 0;								//��ȡ��ǰ�ֲָ���ӯ����������Բ�֧�ִ˹��ܣ�����false����

	virtual bool OnGetStatus(char *, size_t) = 0;								//��ȡ����״̬��������Բ�֧�ִ˹��ܣ�����false����
};










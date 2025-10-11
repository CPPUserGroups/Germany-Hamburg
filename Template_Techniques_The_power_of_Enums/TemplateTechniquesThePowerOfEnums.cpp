#include <cstddef>
#include <tuple>
#include <string>
#include <vector>
#include <magic_enum/magic_enum.hpp>
#include <wchar.h>
#include <format>
#include <atomic>
#include <memory>
#include <map>
#include <variant>

//This was previously defined by windows but just so that it runs on gcc I'll define it here
typedef unsigned long COLORREF;


enum class enumLeverSpec : size_t
{
	Material = 0ULL,
	Name,
	ConstructionLayout,
	MaximumLoad,
	MechanicalAdvantage,
	OperatingTemperatureRange,
	Color
};


using leverSpecSheetTuple = std::tuple<
								std::wstring,
								std::wstring,
								std::vector<size_t>,
								double,
								double,
								std::pair<double,double>,
								COLORREF>;

static_assert(std::tuple_size_v<leverSpecSheetTuple> == magic_enum::enum_count<enumLeverSpec>());

using arrstrLeverSpecs	= std::array<std::wstring,		magic_enum::enum_count<enumLeverSpec>()>;


class CLeverSpecSheet
{
	leverSpecSheetTuple	m_tupRawInfo;
	arrstrLeverSpecs	m_arrStringVer;

public:
	template<enumLeverSpec eSpec>
	[[nodiscard]] const auto&				Get()				const noexcept { return std::get<static_cast<size_t>(eSpec)>(m_tupRawInfo); };

	template<enumLeverSpec eSpec>
	[[nodiscard]] const auto&				GetStr()			const noexcept { return m_arrStringVer[static_cast<int>(eSpec)]; };

	[[nodiscard]] const arrstrLeverSpecs&	GetAllAsStringArr()	const noexcept { return m_arrStringVer; };


	template<enumLeverSpec eSpec, size_t unSpec = static_cast<size_t>(eSpec)>
	void Set(std::wstring_view strvSpec);

	template<enumLeverSpec eSpec, size_t unSpec = static_cast<size_t>(eSpec)>
	void Set(std::tuple_element_t<unSpec, leverSpecSheetTuple> Spec) { std::get<unSpec>(m_tupRawInfo) = Spec; };

	void Set(enumLeverSpec eSpec, std::wstring_view strvSpec);

	void SetAll(const arrstrLeverSpecs& arrStrVer);
};


int main()
{
	CLeverSpecSheet Lever;
	Lever.Set<enumLeverSpec::MaximumLoad>(5.0);
    return Lever.Get<enumLeverSpec::MaximumLoad>();
};


template<enumLeverSpec eSpec, size_t unSpec>
void CLeverSpecSheet::Set(std::wstring_view strvSpec)
{
	using enum enumLeverSpec;
	
	if constexpr (eSpec == ConstructionLayout)
	{
		//...
	}
	else if constexpr (std::is_same_v<std::tuple_element_t<unSpec, leverSpecSheetTuple>, std::wstring>)
	{
		std::get<unSpec>(m_tupRawInfo) = strvSpec;
		m_arrStringVer[unSpec] = Get<eSpec>();
	}
	else if constexpr (std::is_same_v<std::tuple_element_t<unSpec, leverSpecSheetTuple>, double>)
	{
		std::get<unSpec>(m_tupRawInfo) = wcstod(std::wstring{ strvSpec.data(), strvSpec.size() }.c_str(), nullptr);
		m_arrStringVer[unSpec] = std::format(L"{:.2}", Get<eSpec>());
	}
	else
	{
		static_assert(false, "Not all Specs have defined ways of setting them.");
	}
}



/////////////////////////////////////////////////////////Bonus///////////////////////////////////////////////////////////////

template<class T>
struct ISVECTOR
{
	static bool constexpr value = false;
	using ContainedType = T;

};

template<class T>
struct ISVECTOR<std::vector<T>>
{
	static bool constexpr value = true;
	using ContainedType = T;
};

template<typename T>
inline constexpr bool isVector()
{
	return ISVECTOR<T>::value;
}


class CDataStore;

using atomicDataStorePtr		= std::atomic<std::shared_ptr<CDataStore>>;
using atomicConstDataStorePtr	= std::atomic<std::shared_ptr<const CDataStore>>;


///////////////////////////////////////////////////////////////
// "dummy" sparse matrix class
class CSparseMat
{
public:
	struct ELEMENT
	{
		unsigned long	unRow	= 0;
		unsigned long	unCol	= 0;
		double			dValue	= 0.0;
	};

	CSparseMat(unsigned long unNumRows = 0, unsigned long unNumCols = 0) noexcept
	{
		m_unNumRows	= unNumRows;
		m_unNumCols	= unNumCols;
	}

	bool	IsEmpty() const noexcept			{ return ( !m_unNumRows || !m_unNumCols || m_mapElements.empty() ); }

protected:
	unsigned long												m_unNumRows	= 0;
	unsigned long												m_unNumCols	= 0;
	std::map<std::pair<unsigned long, unsigned long>, double>	m_mapElements;
};


///////////////////////////////////////////////////////////////
// "dummy" IUnknown object
class IUnknown
{
public:
	virtual void QueryInterface() = 0;
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};


enum class enumDataFormat : size_t
{
	Char,
	UnsignedChar,
	Short,
	Long,
	Int64,
	Float,
	Double,
	Wstring,
	Sparse,
	Interface,
};

using varFormatType =	std::variant<
							std::vector<signed char>,
							std::vector<unsigned char>,
							std::vector<short>,
							std::vector<long>,
							std::vector<__int64_t>,
							std::vector<float>,
							std::vector<double>,
							std::vector<wchar_t>,
							CSparseMat,
							IUnknown*>;


template<enumDataFormat eFormat, typename rawType = std::variant_alternative_t<static_cast<size_t>(eFormat), varFormatType>>
using FormatType = ISVECTOR<rawType>::ContainedType;


static_assert(std::variant_size_v<varFormatType> == magic_enum::enum_count<enumDataFormat>());


////////////////////////////////////////////////////////////////////////////
// CDataStore

class CDataStoreView;

class CDataStore
{
public:
	CDataStore() noexcept = default;
	CDataStore(enumDataFormat eFormat, long nColCount, long nRowCount, long nSampleCount = 1, long nBlockCount = 1);
	CDataStore(const CDataStore& rSrc) = default;
	~CDataStore();

private:
	friend class CDataStoreView;
	friend class CData;

	CDataStore&	operator=(const CDataStore& rSrc)	= default;

	bool	Create(enumDataFormat eFormat, long nColCount, long nRowCount, long nSampleCount, long nBlockCount);
	void	Clear() noexcept;
	bool	IsEmpty() const noexcept;

	long			m_nNumColumns			= 0;							// LIST_NR_COLUMN
	long			m_nNumRows				= 0;							// LIST_NR_ROWS
	long			m_nNumSamples			= 0;							// LIST_NR_TIMES
	long			m_nNumBlocks			= 0;							// LIST_NR_BLOCKS}


	template <enumDataFormat eFormat>
	auto GetData() const noexcept
	{
		using VarContT = std::variant_alternative_t<static_cast<size_t>(eFormat), decltype(m_Data)>;
		auto* pData = std::get_if<VarContT>(&m_Data);
		
		if constexpr (isVector<VarContT>())
		{
			return (pData) ? *pData : std::span<std::add_const_t<FormatType<eFormat>>>();
		}
		else if constexpr(enumDataFormat::Sparse == eFormat)
		{
			return std::span(pData, pData? 1 : 0);
		}
		else if constexpr(enumDataFormat::Interface == eFormat)
		{
			return std::span(pData, pData? 1 : 0);
		}
		else
		{
			static_assert(false, "unsupported type!");
			return nullptr;
		}
	}

private:
	varFormatType	m_Data;
};

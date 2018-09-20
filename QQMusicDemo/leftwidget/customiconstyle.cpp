#include "customiconstyle.h"

CustomIconStyle::CustomIconStyle()
	: QCommonStyle()
{
	mSize = 20;
}

CustomIconStyle::~CustomIconStyle()
{
}

void CustomIconStyle::setIconSize(int nSize)
{
	mSize = nSize;
}

int CustomIconStyle::pixelMetric(PixelMetric m, const QStyleOption *opt, const QWidget *widget) const
{
	int s = QCommonStyle::pixelMetric(m, opt, widget);
	if (m == QStyle::PM_SmallIconSize)
		s = mSize;
	return s;
}
